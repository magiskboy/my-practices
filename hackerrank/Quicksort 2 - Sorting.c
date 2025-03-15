#include <stdio.h>

void partition(int n, int *a);

int main(){
	int n, a[100000], i;
	scanf("%d", &n);
	for(i=1; i<=n; i++) scanf("%d", &a[i]);
	partition(n, a);
	return 0;
}



void partition(int n, int *a){
	int  x, pl, pr, pe;
	int left[100000], right[100000], equal[100000];
	int i;
	
	x = a[1];
	pl = 0;
	pr = 0;
	pe = 1;
	equal[1] = a[1];
	
	for(i = 2; i<=n; i++)
	if(x < a[i]) right[++pr] = a[i];
	else if(x > a[i]) left[++pl] = a[i];
	else equal[++pe] = a[i];
	
	if(pl > 1 ) partition(pl, left);
	if(pr > 1) partition(pr, right);
	
	for(i = 1; i<=pl; i++) a[i] = left[i];
	for(i = 1; i<=pe; i++) a[pl+i] = equal[i];
	for(i = 1; i<=pr; i++) a[pl+pe+i] = right[i];
	
	for(i=1; i<=n; i++) printf("%d ", a[i]);
	printf("\n");
}