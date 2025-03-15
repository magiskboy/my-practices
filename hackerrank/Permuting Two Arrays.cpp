#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, k;
	int t;
	cin >> t;
	bool flags[t];
	for (int loop = 0; loop < t; loop++){
		cin >> n >> k;
		flags[loop] = true;
		int a[n], b[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];
		for (int i = 0; i < n; i++)
			cin >> b[i];
		sort(a, a+n);
		sort(b, b+n, greater<int>());

		for (int i = 0; i < n && flags[loop]; flags[loop] = a[i] + b[i] < k ? false : true, i++);
	
	}	

	for (int i = 0; i < t; i++)
	if (flags[i])
		cout << "YES\n";
	else
		cout << "NO\n";

	return 0;
}