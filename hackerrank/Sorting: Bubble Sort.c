#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

void swap(int i, int j, int *a){
    int t = a[i];
    a[i] = a[j];
    a[j] = t;
}

int main(){
    int n; 
    int i, j;
    scanf("%d",&n);
    int *a = malloc(sizeof(int) * n);
    for(int a_i = 0; a_i < n; a_i++){
       scanf("%d",&a[a_i]);
    }
    int c = 0;
    for(i = 0; i < n; i++){
        for(j = i + 1; j < n; j++)
            if(a[i] > a[j]){
                c++;
                swap(i, j, a);
            }
    }
    printf("Array is sorted in %d swaps.\n", c);
    printf("First Element: %d\n", a[0]);
    printf("Last Element: %d", a[n-1]);
    return 0;
}
