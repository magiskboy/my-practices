#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define BUFFER_SIZE 100
#define IN_FILENAME "document.txt"
#define OUT_FILENAME "alpha.txt"

int main(int argc, char* argv[]) {
    size_t llen = 0;
    int i;
    FILE *ifp = fopen(IN_FILENAME, "r");
    FILE *ofp = fopen(OUT_FILENAME, "w");
    char *line = (char*)malloc(BUFFER_SIZE * sizeof(char));

    while (!feof(ifp)){
        fgets(line, BUFFER_SIZE, ifp);
        llen = strlen(line);
        for (i = 0; i < llen; ++i) {
            if (isalpha(line[i])) fputc(line[i], ofp);
        }
        memset(line, NULL, BUFFER_SIZE);
    }

    free(line);
    fclose(ifp);
    fclose(ofp);

    return 0;
}
