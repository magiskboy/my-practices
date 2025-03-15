#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

vector<int> eratosthenes( int n ){
	vector<bool> v(n, true);
	int i = 2;
	for ( int i = 2; i < n / 2; i++ ){
		for ( int j = 2; j < n / i; v[i*j] = false, j++ );
	}
	vector<int> arr_primes;
	for ( int i = 2; i < v.size(); i++ ){
		if ( v[i] )
			arr_primes.push_back(i);
	}
	
	return arr_primes;
}

bool is_prime( int n ){
	if ( n < 2 ){
		return false;
	}
	bool flag = true;
	for ( int i = 2; i <= int(sqrt(n)) && flag; i++ ){
		if ( n % i == 0 )
			flag = false;
	}
	return flag;
}

int main(){
	vector<int> v = eratosthenes(100);
	for ( int i = 0; i < v.size(); cout << v[i] << " ", i++ );
	
	return 0;
}
