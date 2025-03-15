#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    int x1; 
    int v1; 
    int x2; 
    int v2; 
    scanf("%d %d %d %d",&x1,&v1,&x2,&v2);
    float n = ((float)(x2-x1))/((float)(v1-v2));
    if(n - (int)n == 0 && n>0) printf("YES");
    else printf("NO");
    
    return 0;
}
