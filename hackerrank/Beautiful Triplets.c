#include <stdio.h>
#include <stdlib.h>

int main(){
	int n, d, *a, *x, c = 0;
	scanf("%d %d", &n, &d);
	a = (int*)malloc(n * sizeof(int));
	x = (int*)malloc(10000 * sizeof(int));
	memset(x, 0, 10000);
	int i, j;
	for(i = 0; i < n; i++){
		 scanf("%d", &a[i]);
		 x[a[i]]++;
	}
	
	for(i = 0; i < n - 2; i++)
	if(x[a[i] + d] > 0)
	if(x[a[i] + 2 * d] > 0) c++;
	
	printf("%d", c);
	return 0;
}