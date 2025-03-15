#include <stdio.h>

int f(int n, int m, int *a, int *b, int x){
	for(int i = 0; i < n; i++) 
	if(x % a[i]) return 0;
	for(int i = 0; i < m; i++)
	if(b[i] % x) return 0; 
	return 1;
}

int main(){
	int n, m, a[10], b[10], max = -200, min = 200;
	int c = 0;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++){
		 scanf(" %d", &a[i]);
		 if(max < a[i]) max = a[i];
	}
	for(int i = 0; i < m; i++){
		scanf(" %d", &b[i]);
		if(min > b[i]) min = b[i];
	}
	if(min > max){
		min = min + max;
		max = min - max;
		min = min - max;
	}
	for(int i = min; i <= max; i++) if(f(n, m, a, b, i)) c++;
	
	printf("%d", c);
	
	return 0;
}