#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    char* s = (char *)malloc(10240 * sizeof(char));
    scanf("%s",s); 
    int n = 1, i;
    for(i=0; i<strlen(s)-1; i++){
        if(islower(s[i]) && isupper(s[i+1])) n++;
    }
    printf("%d", n);
    return 0;
}
