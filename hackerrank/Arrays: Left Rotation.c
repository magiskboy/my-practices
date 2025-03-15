#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
    int n; 
    int k; 
    scanf("%d %d",&n,&k);
    int *a = (int*)malloc(sizeof(int) * (n+1));
    int i;
    for(i=0; i<n; i++) scanf(" %d", &a[(abs(n-k+i)) % n]);
    for(i=0; i<n; i++) printf("%d ", a[i]);
    free(a);
    return 0; 
}
