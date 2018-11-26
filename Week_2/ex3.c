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
    struct udphdr udppkg;
    char* buf = (char*)malloc(BUFFER_SIZE * sizeof(char));
    char* conv_buf = (char*)malloc(5 * sizeof(char));
    FILE *fp = fopen(FILENAME, "w");

    printf("Enter UDP hdr (sport, dport, len, sum): ");
    scanf("%hu %hu %hu %hu", &udppkg.uh_sport, &udppkg.uh_dport, &udppkg.uh_ulen, &udppkg.uh_sum);

    strcpy(buf, "{sport:");
    snprintf(conv_buf, 5, "%hu", udppkg.uh_sport);
    strcat(buf, conv_buf);
    strcat(buf, ",dport:");
    snprintf(conv_buf, 5, "%hu", udppkg.uh_dport);
    strcat(buf, conv_buf);
    strcat(buf, ",ulen:");
    snprintf(conv_buf, 5, "%hu", udppkg.uh_ulen);
    strcat(buf, conv_buf);
    strcat(buf, ",uhsum:");
    snprintf(conv_buf, 5, "%hu", udppkg.uh_sum);
    strcat(buf, conv_buf);
    strcat(buf, "}");

    if (fwrite(buf, sizeof(char), strlen(buf), fp) != strlen(buf)) {
        printf("Write file fail\n");
    }
    else {
        printf("Write file success\n");
    }
    fclose(fp);

    return 0;
}
