#include <stdio.h>
#include <math.h>

void update(int *a,int *b) {
    int tmpa, tmpb;
    tmpa = *a + *b;
    tmpb = abs(*a - *b);
    *a = tmpa;
    *b = tmpb;
}

int main() {
    int a, b;
    int *pa = &a, *pb = &b;
    
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}
