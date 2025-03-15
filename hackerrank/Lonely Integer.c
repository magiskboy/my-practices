#include <stdio.h>

int main(){
	int n, x[100], t;
	scanf("%d", &n);
	for(int i = 0; i < 100; i++) x[i] = 0;
	for(int i = 0; i < n; i++){
		scanf("%d", &t);
		x[t]++; 
	}
	int i = 0;
	while(i < 100 && x[i] != 1) i++;
	printf("%d", i);
	return 0;
}