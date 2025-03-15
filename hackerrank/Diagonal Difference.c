#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    int n; 
    scanf("%d",&n);
    int a[n][n];
    for(int a_i = 0; a_i < n; a_i++){
       for(int a_j = 0; a_j < n; a_j++){
          
          scanf("%d",&a[a_i][a_j]);
       }
    }
    int i;
    int s1 = 0, s2 = 0;
    for(i=0; i<n;i++){
        s1 += a[i][i];
        s2 += a[i][n-1-i];
    }
    printf("%d", abs(s1-s2));
    return 0;
}
