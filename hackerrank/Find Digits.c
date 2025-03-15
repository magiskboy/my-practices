#include <stdio.h>

int main(){
	int n, t, tmp;
	scanf("%d", &n);
	int x[n];
	for(int i = 0; i < n; i++){
		scanf("%d", &t);
		x[i] = 0;
		tmp = t;
		while(tmp != 0){
			if(tmp % 10 != 0)
			if(t % (tmp % 10) == 0) x[i]++;
			tmp /= 10;
		}
	}
	for(int i = 0; i < n; i++) printf("%d\n", x[i]);
	return 0;
}