#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int n, k, b, s = 0;
    scanf(" %d %d", &n, &k);
    int a[n];
    for(int i = 0; i < n; i++){
        scanf(" %d", &a[i]);
        if(i == k) continue;
        else s += a[i];
    }
    scanf("%d", &b);
    if( s/2 - b == 0) printf("Bon Appetit");
    else printf("%d", b - s/2);
    
    return 0;
}
