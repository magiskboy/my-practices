#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE     100
#define HOST            "127.0.0.1"
#define PORT            5000
#define BACKLOG         5

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
            nbytes = read(connect_socket, buf, sizeof(buf));
            if (nbytes < 0) {
                perror("[ERROR READ]");
            }
            else {
                if (buf == NULL) break;
                int i;
                for (i = 0; i < nbytes; ++i) buf[i] = toupper(buf[i]);
                write(connect_socket, buf, sizeof(buf));
                memset(buf, 0, sizeof(buf));
            }
        }
        printf("[DISCONNECT]: %s - %d\n", inet_ntoa(cli_addr.sin_addr), cli_addr.sin_port);
        close(connect_socket);
    }

    return 0;
}
