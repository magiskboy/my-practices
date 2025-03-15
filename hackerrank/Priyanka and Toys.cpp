#include <bits/stdc++.h>

using namespace std;

int find( int start, int *a, int n ){
	int i = start;
	while (i < n && a[i] <= a[start]+4)
		i++;
	return i;
}

int main(){
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];	
	sort(a,a+n);
	
	int i = 0;
	int cost = 0;
	while ( i < n){
		i = find(i, a, n);
		cost++;
	}
	
	cout << cost;	

	return 0;
}