#include <stdio.h>

int main(){
    long int a; 
    long int b; 
    long int c; 
    long int d;
    long int e;
    scanf("%lld %lld %lld %lld %lld",&a,&b,&c,&d,&e);
    long int min = a;
    long int max = a;
    min = min > b ? b : min;
    min = min > c ? c : min;
    min = min > d ? d : min;
    min = min > e ? e : min;
    
    max = max < b ? b : max;
    max = max < c ? c : max;
    max = max < d ? d : max;
    max = max < e ? e : max;
    
    printf("%lld %lld", a + b + c + d + e - max, a + b + c + d + e - min);
    return 0;
}
