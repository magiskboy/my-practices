#include <stdio.h>

int f(int n){
	int a = n;
	while(a % 10 == 0) a /= 10;
	int k = 0;
	while(a != 0){
		k = 10 * k + a % 10;
		a /= 10;
	}
	return k;
}

int abs(int n){
	if(n >= 0) return n;
	else return -n;
}

int main(){
	int i, j, k, count = 0;
	scanf("%d %d %d", &i, &j, &k);
	for(int m = i; m <= j; m++)
	if(abs(m - f(m)) % k == 0) count++;
	printf("%d", count);
	return 0;
}