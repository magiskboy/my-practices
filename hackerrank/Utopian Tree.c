#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int f(int n){
	if(n == 0) return 1;
	else if(n % 2 == 1) return 2 * f(n - 1);
	else return f(n - 1) + 1;
}

int main(){
    int t; 
    scanf("%d",&t);
    int x[t];
    for(int a0 = 0; a0 < t; a0++){
        int n; 
        scanf("%d",&n);
        x[a0] = f(n);
    }
    for(int i = 0; i < t; i++) printf("%d\n", x[i]);
    
    return 0;
}
