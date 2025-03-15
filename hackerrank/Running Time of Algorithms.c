#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
void insertionSort(int n, int *a) {
	int i=1, x = 0, p = 0, j, c = 0;
	for(i = 1; i < n; i++){
		x = a[i];
		p = i-1;
		while((x < a[p]) && (p>=0)){
			a[p+1] = a[p];
			p--;
            c++;
		}
		a[p+1] = x;
	}
    printf("%d", c);
}
int main(void){
   
    int N;
    scanf("%d", &N);
    int x[N], _ar_i;
    for(_ar_i = 0; _ar_i < N; _ar_i++) scanf("%d", &x[_ar_i]); 

    insertionSort(N, x);
   
    return 0;
}
