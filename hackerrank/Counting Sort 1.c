#include <stdio.h>
#include <stdio.h>
int main(){
	int n, a[1000000], i, c[100];
	scanf("%d", &n);
	for(i=0; i<n; i++) scanf("%d", &a[i]);
	memset(c,0,100);
	for(i= 0; i<n; i++) c[a[i]]++;
	for(i = 0; i<100; i++) printf("%d ",c[i]);
	return 0;
}
