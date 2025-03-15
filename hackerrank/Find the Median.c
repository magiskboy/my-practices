#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void sort(int L, int H, int *a){
    if(L<H){
        int i, j, p;
        i = L;
        j = H;
        p = a[(i+j)/2];
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
        sort(L, j, a);
        sort(i, H, a);
    }
}

int main() {
    int a[1000001], n = 0;
    int i;
    scanf("%d", &n);
    for(i = 1; i<=n; i++) scanf("%d", &a[i]);
    sort(1, n, a);
    printf("%d", a[n/2+1]);
    
    return 0;
}
