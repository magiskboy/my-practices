#include <stdio.h>

int f(int n){
	if(n == 0) return 2;
	else return f(n - 1) * 3 / 2;
}

int main(){
	int n, i, s = 0;
	scanf("%d", &n);
	for(i = 0; i < n; i++) s += f(i);
	printf("%d", s);
	return 0;
}