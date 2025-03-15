#include <stdio.h>

int main(){
    int i, j, max = -999, t;
    scanf("%d", &i);
    scanf("%d", &j);
    for(int k = i; k <j; k++){
        for(int l = k + 1; l <=j; l++){
            t = k ^ l;
            if(max < t) max = t;
        }
    }
    printf("%d", max);
    return 0;
}