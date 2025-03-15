#include <stdio.h>

int main(){
	int T;
	int n, m, s;
	scanf("%d", &T);
    int x[T];
	for(int i = 0; i < T; i++){
		scanf("%d %d %d", &n, &m, &s);
        x[i] = (s + m - 1) % n;
        if(x[i] == 0) x[i] = n;
	}
    for(int i = 0; i < T; i++) printf("%d\n", x[i]);
	return 0;
}