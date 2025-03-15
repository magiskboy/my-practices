#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int *a = (int*)malloc(n * sizeof(int)); 
    for(int i = 0; i < n; i++) scanf("%d", &a[(i + n - k) % n]);
    for(int i = 0; i < n; i++) printf("%d ", a[i]);
    return 0;
}
