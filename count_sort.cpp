#include <iostream>
#include <cstring>

using namespace std;

const int _MAX_VALUE = 1000;

void count_sort( int* a, int n, int* v ){
	for ( int i = 0; i < n; i++ ){
		v[a[i]]++;
	}
}

int main(){
	int a[] = { 2, 5, 1, 0, 8, 9, 6, 7, 10, 3 };
	int* v = new int[_MAX_VALUE];
	memset( v, 0, _MAX_VALUE );
	
	count_sort( a, 10, v );
	
	cout << "DESC: ";
	for ( int i = 0; i < _MAX_VALUE; i++ ){
		for ( int j = 0; j < v[i]; cout << i << " ", j++ );
	}
	cout << endl;
	cout << "INC: ";
	for ( int i = _MAX_VALUE-1; i >= 0; i-- ){
		for ( int j = 0; j < v[i]; cout << i << " ", j++ );
	}
	return 0;
}
