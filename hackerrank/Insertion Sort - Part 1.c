#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
void insertionSort(int ar_size, int *a) {
    int x;
    int i, p, j;
    i = ar_size - 1;
    p = i - 1;
    while(i >= 0){
        x = a[i];
        p = i-1;
        while(x < a[p]){
            a[p+1] = a[p];
            p--;
            for(j=0; j<ar_size;j++) printf("%d ", a[j]);
        	printf("\n");
        }
        a[p+1] = x;
        i = p-1;
    }

}
int main(void) {
    int _ar_size;
    scanf("%d", &_ar_size);
    int _ar[_ar_size], _ar_i;
    for(_ar_i = 0; _ar_i < _ar_size; _ar_i++) { 
        scanf("%d", &_ar[_ar_i]); 
    }

    insertionSort(_ar_size, _ar);
    for(_ar_i=0; _ar_i<_ar_size; _ar_i++) printf("%d ", _ar[_ar_i]);
    return 0;
}
