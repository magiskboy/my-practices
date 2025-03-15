#include <stdio.h>

int main(){
	int a[26];
	char st[11];
	for(int i = 0; i < 26; i++) scanf("%d ", &a[i]);
	fflush(stdin);
	gets(st);
	int max = a[(int)st[0] - 97];
	for(int i = 1; i < strlen(st); i++)
	if(max < a[(int)st[i] - 97]) max = a[(int)st[i] - 97];
	printf("%d", strlen(st) * max);
	return 0;
}