#include <stdio.h>

#define MAX 100000
#define MAX_VAL 1000000001

void qsort(int a, int b, int *x){
	if(a < b){
		int i = a, j = b, t = x[(i+j) / 2];
		do{
			while(x[i] < t) i++;
			while(x[j] > t) j--;
			if(i <= j){
				int tmp = x[i];
				x[i] = x[j];
				x[j] = tmp;
				i++;
				j--;
			}
		}while(i <= j);
		qsort(a, j, x);
		qsort(i, b, x);
	}
}


int main(){
	int n, k;
	scanf("%d", &n);
	scanf("%d", &k);
	int a[n], b[n];
	for(int i = 0; i < n; i++) scanf("%d", &a[i]);
	qsort(0, n - 1, a);
	int min = a[k - 1] - a[0];
	for(int i = 1; i < n - k + 1; i++)
	if(min > a[i + k - 1] - a[i]) min = a[i + k - 1] - a[i];
	printf("%d", min);
	return 0;
}