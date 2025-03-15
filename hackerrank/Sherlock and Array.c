#include <stdio.h>

int sum(int L, int H, int *a){
	int i;
	int t = 0;
	for(i = L; i<=H; i++) t += a[i];
	return t;
}

void sort(int L, int H, int *a){
    if(L<H){
        int i, j, p;
        i = L;
        j = H;
        p = a[(i+j)/2];
        do{
            while(a[i] > p) i++;
            while(a[j] < p) j--;
            if(i<=j){
                int t = a[i];
                a[i] = a[j];
                a[j] = t;
                i++;
                j--;
            }
        }while(i<=j);
        sort(L, j, a);
        sort(i, H, a);
    }
}

int main(){
	int T, N, a[100001], i, c[11], s[100001];  // s[j] la tong tu a[1] --> a[j];
	scanf("%d", &T);
	for(i = 1; i<=T; i++){
		scanf("%d", &N);
		int j;
		s[0] = 0;
		for(j = 1; j<=N; j++){
			scanf(" %d", &a[j]);
			s[j] = s[j-1] + a[j];
		}
		if(N==1) c[i] = 1;
		else{
			c[i] = 0;
			j = 1;
			do{
				if(s[j] == s[N]-a[j+1]-s[j]) c[i] = 1;
				j++;
			}while((c[i]==0) && (j<=N-2));
		}
		
	}
	for(i=1; i<=T; i++) if(c[i]==1) printf("YES\n");
	else printf("NO\n");
	return 0;
}