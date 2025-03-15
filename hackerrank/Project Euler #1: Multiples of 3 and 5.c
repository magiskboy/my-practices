#include <stdio.h>
#include <stdlib.h>

int main(){
	int n, T;
	int i, j;
	scanf("%d", &T);
	int *s = (int*)malloc(T * sizeof(int));
	for(i = 0; i<T; i++) s[i] = 0;
	for(i = 0; i<T; i++){
		scanf("%d", &n);
		int *d = (int*)malloc(n*sizeof(int));
		memset(d, 0, n);
		j = 1;
		while(3 * j < n){
			if(d[3*j] == 0){
				s[i] += 3 * j;
				d[3*j] = 1;
			}
			j++;
		}
		
		j = 1;
		while(5*j < n){
			if(d[5*j] == 0){
				s[i] += 5 * j;
				d[5*j] = 1;
			}
			j++;
		}
		free(d);
	}
	for(i = 0; i<T; i++) printf("%d\n", s[i]);
	free(s);
	
	return 0;
}