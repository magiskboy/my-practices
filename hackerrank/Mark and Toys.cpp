#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, k;
	cin >> n >> k;
	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	
	sort(a, a+n);
	
	int c = 0;
	for (int i = 0; i < n && k >= a[i]; k -= a[i], c++, i++);

	cout << c;

	return 0;
}