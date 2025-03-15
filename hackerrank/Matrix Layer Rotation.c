#include <stdio.h>

void rotate(int a[300][300], int m, int n, int j, int k){
	int i;
	int p = 0;
	int b[1200], c[1200];
	for(i = j; i <= n - j - 1; i++) b[p++] = a[j][i];
	for(i = j + 1; i <= m - j - 2; i++) b[p++] = a[i][n - j - 1];
	for(i = n - j - 1; i >= j; i--) b[p++] = a[m - j - 1][i];
	for(i = m - j - 2; i >= j + 1; i--) b[p++] = a[i][j];
	
	k = k % p;
	k = p - k;
	for(i = 0; i < p; i++) c[(i + k) % p] = b[i];

	for(i = j + 1; i <= m - j - 2; i++) a[i][j] = c[--p];
	for(i = j; i <= n - j - 1; i++) a[m - j - 1][i] = c[--p];
	for(i = m - j - 2; i >= j + 1; i--) a[i][n - j - 1] = c[--p];
	for(i = n - j - 1; i >= j; i--)a[j][i] = c[--p];
	
}

int main(){
	int i, j;
	int a[300][300];
	int m, n, k, t;
	
	scanf("%d %d %d", &m, &n, &k);
	for(i = 0; i < m; i++) 
	for(j = 0; j < n; j++){
		scanf("%d", &t);
		a[i][j] = t;
	}
	if(m < n) for(i = 0; i < m / 2; i++) rotate(a, m, n, i, k);
	else for(i = 0; i < n / 2; i++) rotate(a, m, n, i, k);
	
	for(i = 0; i < m; i++){
		for(j = 0; j < n; j++) printf("%d ", a[i][j]);
		printf("\n");
	}
	return 0;
}