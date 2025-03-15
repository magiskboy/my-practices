#include <bits/stdc++.h>

using namespace std;

bool validate( int a, int b, int c){
	return a + b > c && a + c > b && b + c > a;
}

int main(){
	int n;
	cin >> n;
	int a[n];
	int index = -1;
	for (int i = 0; i < n; i++ )
		cin >> a[i];
	sort(a, a + n);
	for (int i = n - 1; i >= 2 && index == -1; i--) 
	if (validate(a[i], a[i-1], a[i-2])){
        	index = i;
    	}

	if (index == -1)
		cout << "-1";
	else{
		cout << a[index-2] << " " << a[index-1] << " " << a[index];	
	}

	return 0;
}