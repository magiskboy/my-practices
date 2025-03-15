#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int n, m;
    int *a, *b;
    int ca[10000], cb[10000];
    int x[10000], p = -1;
    int i, j;
    scanf("%d",&m);
    a = (int*)malloc(m*sizeof(int));
    for(i = 0; i<m; i++){
        scanf(" %d", &a[i]);
        ca[a[i]]++;
    }
    scanf("%d",&n);
    b = (int*)malloc(n*sizeof(int));
    for(i = 0; i<n; i++){
        scanf(" %d", &b[i]);
        cb[b[i]]++;
    }
    
    for(i=0; i<=10000; i++){
        if(ca[i] > 0 && cb[i] > 0)
            if(ca[i] != cb[i]) x[++p] = i;
    }
    free(a);
    free(b);
    for(i=0; i<=p; i++) printf("%d ", x[i]);
    return 0;
}
