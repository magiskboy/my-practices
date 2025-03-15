#include <stdio.h>

int d1 = 0, d2 = 0;

int abs(int n){
	if(n < 0) return -n;
	else return n;
}

void qsort(int L, int H, int *a){
	if(L < H){
		int i = L, j = H, t = a[H];
		do{
			while(a[i] < t) i++;
			while(a[j] > t) j--;
			if(i <= j){
				int tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
				i++;
				j--;
				d1++;
			}
		}while(i <= j);
		qsort(L, j, a);
		qsort(i, H, a);
	}
}

void insertion_sort(int *a, int n){
	int j, temp;
	for (int i = 0; i < n; i++){
		j = i;
		while (j > 0 && a[j] < a[j-1]){
			  temp = a[j];
			  a[j] = a[j-1];
			  a[j-1] = temp;
			  j--;
			  d2++;
		}
	}
}

int main(){
	int n, i, a[1000], b[1000];
	scanf("%d", &n);
	for(i = 0; i < n; i++){
        scanf("%d", &a[i]);
        b[i] = a[i];
    }
	qsort(0, n - 1, a);
    d1++;
	insertion_sort(b, n);
	printf("%d", abs(d1 - d2));
    //printf("\n%d %d", d1, d2);
	return 0;
}