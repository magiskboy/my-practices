#include <bits/stdc++.h>

using namespace std;

int find( int *a, int start, int end ){
	int max = a[start], imax = start;
	for (int i = start +1; i <= end; i++)
	if (max < a[i]){
		imax = i;
		max = a[i];
	}
	return imax;
}

int main(){
	int n, k;
	cin >> n >> k;
	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	
	// dynamic programming
    	int l[n];           // position element max from i to n-1
    	l[n-1] = n-1;
    	for (int i = n-2; i >= 0; i--)
        	l[i] = a[l[i+1]] < a[i] ? i : l[i+1]; 

    
    	int i = 0;
	while( k > 0 && i < n-1 ){
		if (a[i] < a[l[i+1]]){
			swap(a[i], a[l[i+1]]);
			k--;
            l[n-1] = n-1;
    	    for (int j = n-2; j > i; j--)
        	   l[j] = a[l[j+1]] < a[j] ? j : l[j+1]; 

		} 		
		i++;
	}

	for (int i = 0; i < n; i++)
		cout << a[i] << " ";

	return 0;
}