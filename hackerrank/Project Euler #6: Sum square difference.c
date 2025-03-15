#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    int T, n,i,j;
    scanf("%d", &T);
    int *s = (int*)malloc(T * sizeof(int));
    memset(s, 0, T);
    for(i=0; i<T; i++){
        scanf("%d", &n);
        s[i] = (1+n)*n/2;
        s[i] = (int)pow(s[i], 2);
        for(j = 1; j<=n; j++) s[i] -= (int)pow(j,2);
    }
    for(i = 0; i<T; i++) printf("%d\n", s[i]);
    free(s);
    return 0;
}
