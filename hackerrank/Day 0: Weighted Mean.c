#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int n;
    float s = 0.0;
    int s2 = 0;
    scanf("%d", &n);
    int a[n], w[n];
    for(int i = 0; i < n; i++) scanf(" %d", &a[i]);
    for(int i = 0; i < n; i++){
        scanf(" %d", &w[i]);
        s2 += w[i];
    }
    for(int i = 0; i < n; i++) s += a[i]*w[i];
    s /= (float)s2;
    printf("%.1f", s);
    return 0;
}
