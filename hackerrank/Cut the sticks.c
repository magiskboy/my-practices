#include <stdio.h>

int min(int *a, int n){
	int tmp = 99999999;
	for(int i = 0; i<n; i++){
		if(a[i] != 0 && a[i] < tmp) tmp = a[i]; 
	}
	return tmp;
}

int check(int *a, int n){
	int s = 0;
	for(int i = 0; i<n; i++) s += a[i];
	if(s == 0) return 1;
	else return 0;
}

int main(){
	int n;
	int x[1000];
	for(int i = 0; i<1000; i++) x[i] = 0;
	int count = 0;
	scanf("%d", &n);
	int a[n];
	for(int i = 0; i<n; i++) scanf(" %d", &a[i]);
	while(check(a,n) == 0){
		int k = min(a, n);
		count++;
		for(int i = 0; i<n; i++){
			if(a[i] >= k){
				x[count]++;
				a[i] = a[i] - k;
			}
		}
	}
	for( int i= 1; i<=count; i++) printf("%d\n", x[i]);
}