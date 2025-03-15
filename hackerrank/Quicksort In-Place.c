#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void sort(int L, int H, int *a, int k){
    int i = L, j = H, p = a[H];
    if(L<H){
        do{
            while(a[i] < p) i++;
            while(a[j] > p) j--;
            if(i<=j){
                int t = a[i];
                a[i] = a[j];
                a[j] = t;
                i++;
                j--;
            }
        }while(i<=j);
        for(i = 1; i<=k; i++) printf("%d ", a[i]);
        printf("\n");
        sort(L, j, a, k);
        sort(i, H, a, k);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int a[n+1], i;
    for(i = 1; i<=n; i++) scanf(" %d", &a[i]);
    sort(1,n,a,n);    
    return 0;
}
