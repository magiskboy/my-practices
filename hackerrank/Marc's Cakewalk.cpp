#include <bits/stdc++.h>

long long pow( int x, int y ){
	long long s = 1;
	for (int i = 0; i < y; i++ )
		s *= x;
	return s; 
}

int main(){
	int n;
    long long s = 0;
	std::cin >> n;
	int a[n];
	for (int i = 0; i < n; i++)
		std::cin >> a[i];
	std::sort(a, a+n, std::greater<int>());
	for (int i = 0; i < n; i++){
		s += a[i]*pow(2, i);
	}
	std::cout << s;
	return 0;
}