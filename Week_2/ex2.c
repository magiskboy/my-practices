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
    FILE *fp = fopen(FILENAME, "r");

    if (fread(&udppkg, sizeof(struct udphdr), 1, fp) != 1) {
        printf("Can't read from file\n");
    }
    else {
        printf("Source port: %hu\nDestination port: %hu\nLength: %hu\nChecksum: %hu",
                udppkg.uh_sport, udppkg.uh_dport, udppkg.uh_ulen, udppkg.uh_sum);
    }

    fclose(fp);

    return 0;
}
