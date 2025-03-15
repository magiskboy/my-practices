#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int f(int n){
    if(n==1 || n==0) return 1;
    else return n * f(n-1);
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d", f(n));
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}
