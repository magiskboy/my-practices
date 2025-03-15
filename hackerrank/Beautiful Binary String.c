#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int n;
    scanf("%d", &n);
    char *st = (char*)malloc((n + 1) * sizeof(char));
    fflush(stdin);
    scanf("%s", st);
    int c = 0;
    for(int i = 0; i < n - 2; i++){
        if(st[i] == '0' && st[i+1] == '1' && st[i+2] == '0'){
            st[i+2] = '1';
            c++;
        }
    }
    printf("%d", c);
}