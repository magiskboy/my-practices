#include <stdio.h>

#define FILENAME "pkt_hdr.txt"

struct udphdr {
    unsigned short  uh_sport;     /* source port */
    unsigned short  uh_dport;     /* destination dport */
    unsigned short  uh_ulen;      /* upd length */
    unsigned short  uh_sum;       /* udp checksum */
};

int main(int argc, char* argv[]) {
    struct udphdr udppkg;
    FILE *fp = fopen(FILENAME, "w");

    printf("Enter UDP hdr (sport, dport, len, sum): ");
    scanf("%hu %hu %hu %hu", &udppkg.uh_sport, &udppkg.uh_dport, &udppkg.uh_ulen, &udppkg.uh_sum);
    if (fwrite(&udppkg, sizeof(struct udphdr), 1, fp) != 1) {
        printf("Error when write file\n");
    }
    else {
        printf("Write file success\n");
    }
    fclose(fp);

    return 0;
}
