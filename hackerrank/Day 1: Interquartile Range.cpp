#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, t;
	vector<int> E;
	float q1, q3;
	cin >> n;
	for ( int i = 0; i < n; i++ ){
		cin >> t;
		E.push_back(t);
	}

	for ( int i = 0; i < n; i++ ){
		cin >> t;
		int tmp = E[i];
		for ( int j = 0; j < t - 1; j++ )
			E.push_back(tmp);
	}

	sort( E.begin(), E.end() );

	if ( E.size() % 2 == 0 ){
		vector<int> L(E.begin(), E.begin() + E.size() / 2);
		vector<int> U(E.begin() + E.size() / 2, E.end());
		if ( U.size() % 2 == 0 ){
			q1 = (L[L.size()/2-1] + L[L.size()/2])/2.f;
			q3 = (U[U.size()/2-1] + U[U.size()/2])/2.f;
		}
		else{
			q1 = L[L.size()/2+1];
			q3 = U[U.size()/2+1];
		}
	}
	else{
		vector<int> L(E.begin(), E.begin() + E.size() / 2);
		vector<int> U(E.begin() + E.size() / 2 + 1, E.end());
		if ( U.size() % 2 == 0 ){
			q1 = (L[L.size()/2-1] + L[L.size()/2])/2.f;
			q3 = (U[U.size()/2-1] + U[U.size()/2])/2.f;
		}
		else{
			q1 = L[L.size()/2+1];
			q3	 = U[U.size()/2+1];
		}
		
	}

	cout << setprecision(1) << fixed << q3-q1;
	
	
	return 0;
}