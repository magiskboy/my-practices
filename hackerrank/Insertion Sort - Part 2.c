#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
void insertionSort(int n, int *a) {
	int i=1, x = 0, p = 0, j;
	for(i = 1; i < n; i++){
		x = a[i];
		p = i-1;
		while((x < a[p]) && (p>=0)){
			a[p+1] = a[p];
			p--;
		}
		a[p+1] = x;
		for(j=0; j<n; j++) printf("%d ", a[j]);
		printf("\n");
	}
}
int main(void){
   
    int _ar_size;
    scanf("%d", &_ar_size);
    int _ar[_ar_size], _ar_i;
    for(_ar_i = 0; _ar_i < _ar_size; _ar_i++) scanf("%d", &_ar[_ar_i]); 

    insertionSort(_ar_size, _ar);
   
    return 0;
}
