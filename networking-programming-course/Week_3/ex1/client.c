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
        perror("[CONNECT]: fail");
        exit(1);
    }

    strcpy(buf, "Hello server!");
    if (write(connect_socket, buf, sizeof(buf)) < 0) {
        perror("[WRITE]");
        exit(-1);
    }
    else {
        if ((nbytes = read(connect_socket, buf, sizeof(buf))) < 0) {
            perror("[READ]");
            exit(-1);
        }
        else {
            printf("%s\n", buf);
            close(connect_socket);
        }
    }

    return 0;
}
