#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 100
#define FILENAME "document.txt"

int main(int argc, char* argv[]) {
    FILE *fp = fopen(FILENAME, "w");
    char* input_str = (char*)malloc(BUFFER_SIZE * sizeof(char));

    printf("Enter string: ");
    scanf("%[^\n]s", input_str);
    fputs(input_str, fp);

    free(input_str);
    fclose(fp);

    return 0;
}
