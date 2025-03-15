#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    int n;  
    int ne = 0, z = 0, p = 0;
    scanf("%d",&n);
    int arr[n];
    for(int arr_i = 0; arr_i < n; arr_i++){
       scanf("%d",&arr[arr_i]);
        if(arr[arr_i] < 0) ne++;
        else if(arr[arr_i] > 0) p++;
            else z++;
    }
    printf("%f\n%f\n%f", (float)p/n, (float)ne/n, (float)z/n);
    return 0;
}
