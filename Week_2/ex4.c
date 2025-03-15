#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define BUFFER_SIZE 100
#define FILENAME "pkt_hdr_json.txt"

struct udphdr {
    unsigned short  uh_sport;     /* source port */
    unsigned short  uh_dport;     /* destination dport */
    unsigned short  uh_ulen;      /* upd length */
    unsigned short  uh_sum;       /* udp checksum */
};

int main(int argc, char* argv[]) {
    char *buf = (char*)malloc(BUFFER_SIZE * sizeof(char));
    char *token, *token_pair[4];
    int len_buf, i;
    struct udphdr udppkg;
    FILE *fp = fopen(FILENAME, "r");

    fgets(buf, BUFFER_SIZE, fp);
    len_buf = strlen(buf);
    for (i = 0; i < len_buf-1; ++i) {
        buf[i] = buf[i+1];
    }
    for (i = 0; i < 3; ++i) {
        buf[len_buf - i] = NULL;
    }
    len_buf = strlen(buf);
    fclose(fp);

    token = strtok(buf, ",");
    token_pair[0] = (char*)malloc(strlen(token) * sizeof(char));
    strcpy(token_pair[0], token);
    token = strtok(NULL, ",");
    token_pair[1] = (char*)malloc(strlen(token) * sizeof(char));
    strcpy(token_pair[1], token);
    token = strtok(NULL, ",");
    token_pair[2] = (char*)malloc(strlen(token) * sizeof(char));
    strcpy(token_pair[2], token);
    token = strtok(NULL, ",");
    token_pair[3] = (char*)malloc(strlen(token) * sizeof(char));
    strcpy(token_pair[3], token);

    char *tmp;
    tmp = strtok(token_pair[0], ":");
    tmp = strtok(NULL, ":");
    udppkg.uh_sport = (unsigned short)strtoul(tmp, NULL, 0);
    tmp = strtok(token_pair[1], ":");
    tmp = strtok(NULL, ":");
    udppkg.uh_dport = (unsigned short)strtoul(tmp, NULL, 0);
    tmp = strtok(token_pair[2], ":");
    tmp = strtok(NULL, ":");
    udppkg.uh_ulen = (unsigned short)strtoul(tmp, NULL, 0);
    tmp = strtok(token_pair[3], ":");
    tmp = strtok(NULL, ":");
    udppkg.uh_sum = (unsigned short)strtoul(tmp, NULL, 0);


    printf("Source port: %hu\nDestination port: %hu\nLength: %hu\nChecksum: %hu",
            udppkg.uh_sport, udppkg.uh_dport, udppkg.uh_ulen, udppkg.uh_sum);

    return 0;
}
