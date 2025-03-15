#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int V, n, ar[100];
    scanf("%d", &V);
    scanf("%d", &n);
    int i;
    for(i=0; i<n; i++) scanf("%d", &ar[i]);
    for(i=0; i<n; i++) if(V == ar[i]) break;
    printf("%d",i);
    return 0;
}
