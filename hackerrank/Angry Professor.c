#include <stdio.h>
int main(){
    int n, k, t, p;
    int a[1000], x[10];
    scanf("%d", &t);
    for(int i = 0; i < t; i++){
        scanf("%d %d", &n, &k);
        x[i] = 0;
        p = 0;
        for(int j = 0; j < n; j++){
            scanf("%d", &a[j]);
            if(a[j] <= 0) p++;
        }
        if(p >= k) x[i] = 1;
    }
    for(int i = 0; i < t; i++)
        if(x[i]) printf("NO\n");
        else printf("YES\n");
    return 0;
}
