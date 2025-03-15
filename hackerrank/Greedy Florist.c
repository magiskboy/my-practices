#include<stdio.h>

void sort(int L, int H, int *a){
    if(L<H){
        int i = L, j = H, p = a[(i+j)/2];
        do{
            while(a[i] > p) i++;
            while(a[j] < p) j--;
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

    int s = 0;
	int n, k;
   	int i, tmp;
   	int c[1000];
	int *a = (int*)malloc(1000*sizeof(int));
    
   	scanf("%d %d", &n, &k);
   	for(i=0; i<n; i++){
    	scanf("%d", &c[i]);
   	}
    

		sort(0, n-1, c);
	    for(i=0; i<n; i++){
            tmp = i / k;
            s += (tmp + 1) * c[i];
        }
	printf("%d", s);
}
