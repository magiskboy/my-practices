#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	int a[n];
	for ( int i = 0; i < n; i++ ) 
		cin >> a[i];
	int min = a[0];
	int max = a[0];
	int cmin = 0;
	int cmax = 0;
	for ( int i = 1; i < n; i++ ){
		if ( min > a[i] ){
			min = a[i];
			cmin++;
		}

		if ( max < a[i] ){
			max = a[i];
			cmax++;
		}

	}
	
	cout << cmax << " " << cmin;
	return 0;
}