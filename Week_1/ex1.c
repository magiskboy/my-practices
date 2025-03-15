#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_SIZE 100

int main(int argc, char* argv[]) {
    size_t len_str = 0;
    size_t c_digit = 0, c_alpha = 0, c_symbol = 0;
    char* input_str = (char*)malloc(BUFFER_SIZE * sizeof(char));

    printf("Enter string: ");
    scanf("%[^\n]s", input_str);
    len_str = strlen(input_str);

    int i;
    for (i = 0; i < len_str; ++i) {
        if (isdigit(input_str[i])) ++c_digit;
        else if (isalpha(input_str[i])) ++c_alpha;
        else ++c_symbol;
    }

    printf("Alpha: %d\nDigit: %d\nSymbol: %d", c_alpha, c_digit, c_symbol);
    free(input_str);

    return 0;
}
