#include <stdio.h>

int main(){
	int n;
	scanf("%d", &n);
	int a[n], c = 0, p = 0;
	for(int i = 0; i < n; i++) scanf("%d", &a[i]);
	while(p < n - 1){
		if(p + 1 == n - 1) p++;
		else if(a[p + 2] == 1) p++;
		else p += 2;
		c++; 
	}
	printf("%d", c);
	return 0;
}