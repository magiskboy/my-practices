
#include <stdio.h>

int main(){
    int d1; 
    int m1; 
    int y1; 
    scanf("%d %d %d",&d1,&m1,&y1);
    int d2; 
    int m2; 
    int y2; 
    int s = 0;
    scanf("%d %d %d",&d2,&m2,&y2);
    if(y1 > y2) s = 10000;
    else if(y1 == y2){
        if(m1 > m2) s = 500 * (m1 - m2);
        else if(m1 == m2){
            if(d1 > d2) s = 15 * (d1 - d2);
        }
    }
    printf("%d", s);
    
    return 0;
}
