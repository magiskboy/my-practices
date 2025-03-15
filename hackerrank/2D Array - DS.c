#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    int arr[6][6];
    for(int arr_i = 0; arr_i < 6; arr_i++){
       for(int arr_j = 0; arr_j < 6; arr_j++){
          
          scanf("%d",&arr[arr_i][arr_j]);
       }
    }
    
    
    
    int s[16];
    int i, j;
    int m;
    for(i=0; i<=3; i++){
        for(j=0; j<=3;j++){
            s[i*4+j] =  arr[i][j] + arr[i][j+1] + arr[i][j+2] + arr[i+1][j+1] + arr[i+2][j] + arr[i+2][j+1] + arr[i+2][j+2];
        }
        
    }
    m = s[0];
    for(i=1; i<16; i++) m = m >= s[i] ? m : s[i];
    printf("%d", m);
    return 0;
}
