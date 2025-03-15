#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
	char *s = (char*)malloc(102400 * sizeof(char));
	int n, po, pe;
	char *odd[10000];
	char *even[10000];
	for(int i = 0; i < 100; i++){
		odd[i] = (char*)malloc(102400 * sizeof(char));
		even[i] = (char*)malloc(102400 * sizeof(char));
	}
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%s", s);
		po = -1; pe = -1;
		for(int j = 0; j < strlen(s); j+=2) even[i][++pe] = s[j];
		for(int j = 1; j < strlen(s); j+=2) odd[i][++po] = s[j];
	}
	for(int i = 0; i < n; i++) printf("%s %s\n",even[i], odd[i]);
    free(s);
}