#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int f(int i, int *a){
    if(a[i - 1] != -1) return a[i - 1] ^ i;
    else return f(i - 1, a) ^ i;
}

int main(){
    int n, q, r, *a = (int*)malloc(100000000 * sizeof(int));
    memset(a, -1, 100000000);
    scanf("%d", &n);
    int x[n];
    for(int i = 0; i < n; i++){
        scanf("%d %d", &q, &r);
        if(a[q] == -1) a[q] = f(q, a);
        x[i] = a[q];
        for(int j = q + 1; j <= r; j++){
            if(a[j] == -1) a[j] = f(j, a);
            x[i] = x[i] ^ a[j];
        }
    }
    for(int i = 0; i < n; i++) printf("%d\n", x[i]);
    return 0;
}
