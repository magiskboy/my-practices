#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE     1024
#define FILENAME_BUFFER 200
#define HOST            "127.0.0.1"
#define PORT            5000
#define BACKLOG         5
#define MAX_FILE        100

/* Tag value */
#define LS_TAG          1
#define DOWNLOAD_TAG    2
#define DONE_TAG        3


int listdir(const char *dname, char** filenames) {
    struct dirent *de;
    unsigned counter = 0;
    DIR *dir = opendir(dname);
    if (dir == NULL) {
        return -1;
    }

    while ((de = readdir(dir)) != NULL) {
        strcpy(filenames[counter++], de->d_name);
    }
    closedir(dir);

    return counter;
}

int ls_handler(const int connect_socket) {
    char* filenames[MAX_FILE];
    int i, counter = 0;
    for (i = 0; i < MAX_FILE; ++i) filenames[i] = (char*)malloc(FILENAME_BUFFER * sizeof(char));
    counter = listdir("files", filenames);

    /*
     * @TODO
     * Send tag value
     */
    char buf[FILENAME_BUFFER];
    buf[0] = LS_TAG;
    buf[1] = counter;
    if (write(connect_socket, buf, sizeof(buf)) < 0) {
        perror("[ERROR]");
        exit(1);
    }

    /*
     * @TODO
     * Send filenames
     */
    for (i = 0; i < counter; ++i) {
        if (write(connect_socket, filenames[i], FILENAME_BUFFER) < 0) {
            perror("[ERROR]");
        }
    }

    /*
     * @TODO
     * End transfer
     */
    buf[0] = DONE_TAG;
    if (write(connect_socket, buf, sizeof(buf)) < 0) {
        perror("[ERROR]");
    }

    return 0;
}

void download_handler(const int connect_socket, const char* filename) {
    printf("%s\n", filename);

}

void default_handler(const int connect_socket) {
    char buf[FILENAME_BUFFER];
    buf[0] = DONE_TAG;
    if (write(connect_socket, buf, sizeof(buf)) < 0) {
        perror("[ERROR]");
    }
}

int main(int argc, char* argv[]) {
    int listen_socket;
    int connect_socket;
    struct sockaddr_in sockaddr;
    struct sockaddr_in cli_addr;
    socklen_t cli_addr_len = sizeof(cli_addr);
    char buf[BUFFER_SIZE];
    int nbytes = 0;

    if ((listen_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("[CREATE CONNECTION]");
        exit(1);
    }

    sockaddr.sin_family = AF_INET;
    sockaddr.sin_port = htons(PORT);
    sockaddr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(listen_socket, (struct sockaddr*) &sockaddr, sizeof(sockaddr)) < 0) {
        perror("[BIND]");
        exit(1);
    }

    if (listen(listen_socket, BACKLOG) < 0) {
        perror("[LISTEN]");
        exit(1);
    }
    else {
        printf("[LISTENING]: %s - %d\n", HOST, PORT);
        fflush(stdout);
    }

    // Block here
    connect_socket = accept(listen_socket, (struct sockaddr*) &cli_addr, &cli_addr_len);

    if (connect_socket < 0) {
        perror("[ACCEPT]");
        exit(1);
    }
    else if (connect_socket > 0) {
        char *addr_str = (char*)malloc(16 * sizeof(char));
        addr_str = inet_ntoa(cli_addr.sin_addr);
        printf("[CONNECTED]: %s - %d\n", addr_str, cli_addr.sin_port);
        while (1) {
            memset(buf, 0, sizeof(buf));
            nbytes = read(connect_socket, buf, sizeof(buf));
            if (nbytes < 0) {
                perror("[ERROR READ]");
            }
            else {
                if (buf == NULL) break;

                switch (buf[0]) {
                    case LS_TAG:
                        ls_handler(connect_socket);
                        break;

                    case DOWNLOAD_TAG:
                        download_handler(connect_socket, buf);
                        break;

                    default:
                        default_handler(connect_socket);
                }
            }
        }
        printf("[DISCONNECT]: %s - %d\n", inet_ntoa(cli_addr.sin_addr), cli_addr.sin_port);
        close(connect_socket);
    }


    return 0;
}
