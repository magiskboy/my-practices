#include <stdio.h>
#include <math.h>

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


int main(){
	int a[200000], t = 0, min = 9999999;
	int n, i, j;
	scanf("%d", &n);
	for(i = 1; i <=n; i++) scanf(" %d", &a[i]);
    sort(1, n, a);
	for(i = 1; i<=n-1; i++){
        t = abs(a[i] - a[i+1]);
        min = min >= t ? t : min;
    }
	for(i =1; i<=n-1; i++) if(abs(a[i] - a[i+1]) == min) printf("%d %d ", a[i],a[i+1]);
	return 0;
}