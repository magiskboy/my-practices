#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    long n; 
    scanf("%ld",&n);
    int i, c = 0;
    for(i=0; i<=n; i++) if((n+i) == (n ^ i)) c++;
    printf("%d", c);
    return 0;
}
