#include <bits/stdc++.h>

int abs(int n){
	return n < 0 ? -n : n;
}

int main(){
	int n; 
	std::cin >> n;
	int min = 999999999;
	int a[n];
	for (int i = 0; i < n; i++)
		std::cin >> a[i];
	std::sort(a, a+n);
	for (int i = 0; i < n-1; i++) 
	min = abs(a[i]-a[i+1]) >= min ? min : abs(a[i]-a[i+1]);
	std::cout << min;
	return 0;
}