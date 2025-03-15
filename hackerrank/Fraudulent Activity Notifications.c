#include <stdio.h>

int f(int m, int n, int *a){
	if((n - m + 1) % 2) return a[m + (n - m) / 2];
	else return (int)((a[m + (n - m) / 2] + a[m + (n - m) / 2 + 1]) / 2);
}

int main(){
	int n, k, tmp, c = 0;
	scanf("%d %d", &n, &k);
	int a[n + 1], b[n + 1], t[n + 1];
	b[0] = -1;
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		if(i > k)
		if(2 * t[i - 1] <= a[i]) c++;
		tmp = a[i];
		int j = i - 1;
		while(b[j] > tmp && j >= 1){
			b[j + 1] = b[j];
			j--;
		}
		b[++j] = tmp;
		t[i - 1] = f(i - k, i - 1, b);
	}
	
	printf("%d", c);
	return 0;
}