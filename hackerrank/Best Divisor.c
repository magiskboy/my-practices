#include <math.h>
#include <stdio.h>

int sum(int n){
    int m = n, s = 0;
    while(m != 0){
        s += m % 10;
        m /= 10;
    }
    return s;
}

int main(){
    int n; 
    scanf("%d",&n);
    int i, k;
    int smax = sum(n);
    int max = n;
    for(i = 2; i < n / 2; i++){
        if(n % i == 0){
            k = n / i;
            if(smax < sum(k)){
            	smax = sum(k);
            	max = k;
            }
            else if(smax == sum(k)){
            	if(max < k) max = k;
            }
        }
    }
    printf("%d", max);
    return 0;
}
