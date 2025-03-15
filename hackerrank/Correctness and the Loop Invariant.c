#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>


void insertionSort(int n, int a[]) {
    int i=1, x = 0, p = 0, j;
	for(i = 1; i < n; i++){
		x = a[i];
		p = i-1;
		while((x < a[p]) && (p>=0)){
			a[p+1] = a[p];
			p--;
		}
		a[p+1] = x;
	}
    for(j=0;j<n;j++)
    {
        printf("%d",a[j]);
        printf(" ");
    }
}
int main(void) {

    int N;
    scanf("%d", &N);
    int arr[N], i;
    for(i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    insertionSort(N, arr);

    return 0;
}
