#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define BUFFER_SIZE         1024
#define FILENAME_BUFFER     200

/* Tag value */
#define LS_TAG              1
#define DOWNLOAD_TAG        2
#define DONE_TAG            3


int ls_response_handler(const int connect_socket, const int num_of_msg) {
    char buf[FILENAME_BUFFER];
    char listfile[FILENAME_BUFFER * num_of_msg + 2 * num_of_msg];
    memset(listfile, 0, sizeof(listfile));
    printf("[RESPONSE]: %d files\n\t", num_of_msg);
    do {
        if (read(connect_socket, buf, sizeof(buf)) < 0) {
            perror("[ERROR]");
            exit(1);
        }
        fflush(stdout);
        if (buf[0] == DONE_TAG) {
            break;
        }
        else {
            strcat(listfile, buf);
            strcat(listfile, ", ");
        }
    } while (1);
    printf("%s\n", listfile);

    return 0;
}

void download_response_handler(const int connect_socket, const int num_of_msg) {

}

void default_response(const int connect_socket) {

}

int main(int argc, char* argv[]) {
    char* server_host = (char*)malloc(16 * sizeof(char));
    unsigned server_port;
    int connect_socket;
    struct sockaddr_in serveraddr;
    char message[BUFFER_SIZE];
    char buf[BUFFER_SIZE];
    int nbytes;

    printf("Enter server host: ");
    scanf("%s", server_host);
    printf("Enter server port: ");
    scanf("%u", &server_port);

    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(server_port);
    serveraddr.sin_addr.s_addr = inet_addr(server_host);

    if ((connect_socket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("[CREATE SOCKET]");
        exit(1);
    }

    if (connect(connect_socket, (struct sockaddr*) &serveraddr, sizeof(serveraddr)) < 0) {
        perror("[CONNECT]");
        exit(1);
    }

    while (strcmp(message, "exit") != 0) {
        printf("[COMMAND]: ");
        scanf("%s", message);

        char command[1];
        command[0] = 0;
        if (strcmp(message, "@ls") == 0) command[0] = LS_TAG;
        else if (strcmp(message, "@download") == 0) command[0] = DOWNLOAD_TAG;
        else continue;

        if (write(connect_socket, command, sizeof(command)) < 0) {
            perror("[ERROR]");
        }
        else {
            if ((nbytes = read(connect_socket, buf, sizeof(buf))) < 0) {
                perror("[ERROR]");
            }
            else {
                /*
                 * @TODO
                 * Handler response
                 */
                if (buf == NULL) break;
                switch (buf[0]) {
                    case LS_TAG:
                        ls_response_handler(connect_socket, buf[1]);
                        break;

                    case DOWNLOAD_TAG:
                        download_response_handler(connect_socket, buf[1]);
                        break;

                    default:
                        default_response(connect_socket);
                }
            }
        }
    }
    close(connect_socket);

    return 0;
}
