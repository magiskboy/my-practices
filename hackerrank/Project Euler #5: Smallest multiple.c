#include <stdio.h>
#include <stdlib.h>

int UCLN(int a, int b){
	if(b == 0) return a;
	else return UCLN(b, a % b);
}

int BCNN(int a, int b){
	return (a * b) / UCLN(a, b);
}


int main(){
	int n, T;
	int s[100];
	int i, j;
	for(i = 0; i<100; i++) s[i] = 1;
	scanf("%d", &T);
	for(i = 0; i<T; i++){
		scanf("%d", &n);
		for(j = 2; j<=n; j++) s[i] = BCNN(s[i], j);
	}
	for(i = 0; i < T; i++) printf("%d\n", s[i]);
	return 0;
}