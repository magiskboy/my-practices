#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	int a[n];
	for ( int i = 0; i < n; cin >> a[i], i++ );
	sort(a, a+n);
	int c = 1;
	for ( int i = n-2; i >= 0; i-- )
	if ( a[i] == a[n-1] ) c++;
	cout << c;
	return 0;
}