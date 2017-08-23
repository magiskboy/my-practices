#include <iostream>

using namespace std;

int fib( int n ){
	int a = 0, b = 1, c;
	for ( int i = 1; i < n; c = a + b, a = b, b = c, i++ );
	return c;
}

int main(){
	cout << fib(10);	
	return 0;
}
