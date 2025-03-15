#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, count = 0; 
    scanf("%d",&n);
    int *a = malloc(sizeof(int) * n);
    int *c = (int*)malloc(sizeof(int) * 105);
    memset(c,0,100);
    int i;
    for(i=0; i<n; i++){
        scanf(" %d", &a[i]);
        c[a[i]]++;
    }
    for(i = 1; i<=100; i++)
        if(c[i] > 1) count += c[i] / 2;
    printf("%d", count);
    return 0;
}
