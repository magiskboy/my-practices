#include <stdio.h>

typedef struct number{
	int v, i;
};

int abs(int n){
	if(n >= 0) return n;
	else return -n;
}

void sort(int a, int b, struct number *x){
	if(a < b){
		int i = a, j = b;
		struct number t = x[(i + j) / 2];
		do{
			while(x[i].v < t.v) i++;
			while(x[j].v > t.v) j--;
			if(i <= j){
				struct number tmp = x[i];
				x[i] = x[j];
				x[j] = tmp;
				i++;
				j--;
			}
		}while(i <= j);
		sort(a, j, x);
		sort(i, b, x);
	}
}

int main(){
	struct number a[1000];
	int n, min = 999999999, t;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		a[i].i = i;
		scanf("%d", &t);
		a[i].v = t;
	}
	sort(0, n - 1, a);
	for(int i = 1; i < n; i++)
	if(a[i].v == a[i - 1].v && min > abs(a[i].i - a[i - 1].i)) min = abs(a[i].i - a[i - 1].i);
	if(min == 999999999) printf("-1");
	else printf("%d", min);
	return 0;
}