#include <stdio.h>
#include <math.h>

int abs(int n){
	if(n < 0) return -n;
	else return n;
}

int f(int n){
	if(n == 1) return 0;
	if(n == 2 || n == 3) return 1;
	int i = 2;
	while(i <= (int)sqrt(n)){
		if(n % i == 0) return 0;
		i++;
	}
	return 1;
}

int main(){
	int i, j, m, n, c = 0;
	scanf("%d %d", &m, &n);
	if(m % 2 == 0) m++;
	if(n % 2 == 0) n--;
	for(i = m; i <= n - 2; i += 2)
	if(f(i) && f(i + 2)) c++;
	printf("%d", c);
	return 0;
}