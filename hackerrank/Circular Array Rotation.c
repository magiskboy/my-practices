#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    int n; 
    int k; 
    int q; 
    scanf("%d %d %d",&n,&k,&q);
    int a[n], b[n], m[q];
    int i;
    for(i = 0; i<n; i++) scanf(" %d", &a[i]);
    for(i = 0; i<q; i++) scanf("%d", &m[i]);
    
    for(i=0; i<n; i++) b[(i+k) % n] = a[i];
    
    for(i = 0; i<q; i++) printf("%d\n", b[m[i]]);
    return 0;
}
