#include <stdio.h>
#include <stdlib.h>

int main(){
	int s, t, x, y, m, n, c1 = 0, c2 = 0, tmp;
	scanf("%d %d", &s, &t);
	scanf("%d %d", &x, &y);
	scanf("%d %d", &m, &n); 
	for(int i = 0; i < m; i++){
		scanf("%d ", &tmp);
		if(x + tmp <= t && x + tmp >= s) c1++;
	}
	for(int i = 0; i < n; i++){
		scanf("%d ", &tmp);
		if(y + tmp <= t && y + tmp >= s) c2++;
	}
	printf("%d\n%d", c1, c2);
	return 0;
}