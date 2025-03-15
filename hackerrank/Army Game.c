#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    int n; 
    int m; 
    scanf("%d %d",&n,&m);
    int i, j, a, b, c;
    i = m / 2;
    j = n / 2;
    a = i * j;
    b = m * n - 4 * i * j;
    if(b % 2) b = b / 2 + 1;
    else b = b / 2;
    c = a + b;
    printf("%d", c);
    return 0;
}
