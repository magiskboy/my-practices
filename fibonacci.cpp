#include <iostream>

int fib( int n ){
	int a = 0, b = 1, c;
	for ( int i = 1; i < n - 1; b += a, a = b - a, i++ );
	return b;
}

int main(){
	std::cout << fib(10) << std::endl;	
	return 0;
}
