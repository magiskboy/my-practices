#include <stdio.h>

int main(){
    int n; 
    scanf("%d",&n);
    
    int p = -1;
    int a[1000000];
    
    int max = 0, tmp = 0;;
    while(n != 0){
        a[++p] = n % 2;
        n /= 2;
        if(a[p] == 1) tmp++;
        else{
            max = max <= tmp ? tmp : max;
            tmp = 0;
        }
    }
    max = max < tmp ? tmp : max;
    printf("%d", max);
    return 0;
}
