#include <stdio.h>
#include <stdlib.h>

int main(){
	int n, c[100];
	scanf("%d", &n);
	int ar[n], i, j;
	for(i=0; i<100; i++) c[i] = 0;
	for(i=0; i<n; i++){
		scanf(" %d", &ar[i]);
		c[ar[i]]++;
	}
	for(i = 0; i<100; i++) if(c[i]>0) for(j = 0; j<c[i]; j++) printf("%d ", i);
	return 0;
}