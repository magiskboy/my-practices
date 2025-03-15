#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 100
#define FILENAME "document.txt"

int main(int argc, char* argv[]) {
    FILE *fp = fopen(FILENAME, "r");
    char *line = (char*)malloc(BUFFER_SIZE * sizeof(char));

    while (!feof(fp)) {
        fgets(line, BUFFER_SIZE, fp);
        printf("%s", line);
        memset(line, NULL, BUFFER_SIZE);
    }

    free(line);
    fclose(fp);

    return 0;
}
