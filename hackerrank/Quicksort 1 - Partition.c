#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>
void partition(int n, int *a){
    int p = a[0], pl, pr, pe = 0;
    int left[100], right[100], equal[100];
    int i;
    pl = pr = -1;
    equal[pe] = a[0];
    for(i=1; i<n; i++){
        if(a[i] < p) left[++pl] = a[i];
        else if(a[i] > p) right[++pr] = a[i];
        else equal[++pe] = a[i];
    }
    if(pl > -1) for(i=0; i<=pl; i++) printf("%d ", left[i]);
    for(i=0; i<=pe; i++) printf("%d ", equal[i]);
    if(pr > -1) for(i=0; i<=pr; i++) printf("%d ", right[i]);
}
int main(void){
   
    int _ar_size;
    scanf("%d", &_ar_size);
    int _ar[_ar_size], _ar_i;
    for(_ar_i = 0; _ar_i < _ar_size; _ar_i++) scanf("%d", &_ar[_ar_i]); 
    partition(_ar_size, _ar);
}