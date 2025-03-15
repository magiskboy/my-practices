#include <stdio.h>
#include <math.h>

int main(){
	int n, a, b, tmp;
	scanf("%d", &n);
	int x[n];
	for(int i = 0; i < n; i++){
		scanf("%d %d", &a, &b);
		tmp = (int)sqrt(a);
		if(tmp * tmp == a) x[i] = 1;
		else x[i] = 0;
		tmp++;
		while(tmp * tmp <= b){
			x[i]++;
			tmp++;
		}
	}
	for(int i = 0; i < n; i++) printf("%d\n", x[i]);
	return 0;
}