#include <stdio.h>

int main(){
	int n, c[101], t;
	for(int i = 0; i <= 100; i++) c[i] = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &t);
		c[t]++;
	}
	int max = c[0];
	for(int i = 1; i <= 100; i++) if(max < c[i]) max = c[i];
	printf("%d", n - max);
	return 0;
}