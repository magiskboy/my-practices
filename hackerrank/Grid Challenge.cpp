#include <bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin >> t;
	bool r[t];
	for (int l = 0; l < t; l++){
		r[l] = true;
		int n;
		cin >> n;
		string m[n];
		for( int i = 0; i < n; i++ ){
			cin >> m[i];
			sort(m[i].begin(), m[i].end());
		} 
		for ( int i = 0; i < n-1; i++ )
		for (int j = 0; j < n;  j++)
		if (m[i][j] > m[i+1][j]){
			r[l] = false;
			break;
		}
	}	
	
	for (int i = 0; i < t; i++ )
	if (r[i])
		cout << "YES\n";
	else
		cout << "NO\n";
	return 0;
}