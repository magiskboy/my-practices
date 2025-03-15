#include <stdio.h>

int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	int a[n], E = 100, p = 0;
	for(int i = 0; i < n; i++) scanf("%d", &a[i]);
	do{
		p = (p + k) % n;
		E  -= (1 + 2 * a[p]);
	}while(p != 0);
	printf("%d", E);
	return 0;
}