#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	string s[n];
	int h[n];
	for ( int i = 0; i < n; cin >> s[i], i++ );
	for ( int i = 0; i < n; cin >> h[i], i++ );
	int m;
	cin >> m;
	int min_n = 999999;
	int max_n = -999999;
	for ( int i = 0; i < m; i++ ){
		int a, b;
		int sum = 0;
		string st;
		cin >> a >> b >> st;
		for ( int i = a; i <= b; i++ ){
			int pos = 0;
			while( st.find(s[i], pos) != string::npos && pos < st.length() ){
				sum += h[i];
				pos = st.find(s[i], pos) + 1;
			}
		}
		
		if ( sum > max_n )
			max_n = sum;
		if ( sum < min_n )
			min_n = sum;
	}
	
	cout << min_n << " " << max_n;
	
	return 0;
}