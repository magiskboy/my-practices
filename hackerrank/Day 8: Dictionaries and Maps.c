#include <stdio.h>
#include <string.h>
#include <stdlib.h>



int main(){
	int n;
	scanf("%d", &n);
	char *name[n], *phone[n], *kname[n], *rname[n], *rphone[n];
	for(int i = 0; i < n; i++){
		name[i] = (char*)malloc(102400 * sizeof(char));
		phone[i] = (char*)malloc(102400 * sizeof(char));
		kname[i] = (char*)malloc(102400 * sizeof(char));
		rname[i] = (char*)malloc(102400 * sizeof(char));
		rphone[i] = (char*)malloc(102400 * sizeof(char));
	}
 	
 	for(int i = 0; i < n; i++){
 		scanf(" %s %s", name[i], phone[i]);
 	}
 	for(int i = 0; i < n; i++){
 		scanf("%s", kname[i]);
 		strcpy(rname[i], "Not found");
 		for(int j = 0; j < n; j++) if(strcmp(kname[i], name[j]) == 0){
 			strcpy(rname[i], name[j]);
 			strcpy(rphone[i], phone[j]);
 			break;
 		}
 	}

	for(int i = 0; i< n; i++)
	if(strlen(rphone[i]) > 0) printf("%s=%s\n", rname[i], rphone[i]);
	else printf("%s\n", rname[i]);
	return 0;
}