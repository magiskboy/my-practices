#include <iostream>

using namespace std;

long long pow(int a, int x){
	if(x == 0) return 1;
	else return a * pow(a, x - 1);
}

int g(long long n){
	long long m = n;
	int c = 0;
	while(m){
		c++;
		m /= 10;
	}
	return c;
}

int f(long long n){
	if(n == 1) return 1;
	else{
		long long m = n * n;
		int t;
		int k = g(m);
        t = k % 2 ? k / 2 + 1 : k / 2;
        if(m % pow(10, t) + m / pow(10, t) == n) return 1;
		return 0;
	}
}


int main(){
	int i, j, k, count = 0;
	cin >> i;
	cin >> j;
	for(k = i; k <= j; k++)
	if(f(k)){
		cout << k << " ";
		count++;
	}
	if(count == 0) cout << "INVALID RANGE";
	return 0;
}