#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define BUFFER_SIZE 100

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
        printf("[SEND]: ");
        scanf("%s", message);

        if ((nbytes = write(connect_socket, message, sizeof(message))) < 0) {
            perror("[ERROR]");
        }
        else {
            if ((nbytes = read(connect_socket, buf, sizeof(buf))) < 0) {
                perror("[ERROR]");
            }
            else {
                printf("[RESPONSE]: %s\n", buf);
            }
        }
    }
    close(connect_socket);

    return 0;
}
