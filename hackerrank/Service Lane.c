#include <stdio.h>
#include <stdlib.h>

int main(){
	int T, N, *a, x[1000];
	int i, j, k, l;
	scanf("%d %d", &N, &T);
	a = (int*)malloc(N * sizeof(int));
	for(i = 0; i < N; i++) scanf("%d", &a[i]); 
	for(k = 0; k < T; k++){
		scanf("%d %d", &i, &j);
        int min = 999999;
		for(l = i; l <= j; l++)
		min = min > a[l] ? a[l] : min;
        x[k] = min;
	}
	for(i = 0; i < T; i++) printf("%d\n", x[i]);
	return 0;
}