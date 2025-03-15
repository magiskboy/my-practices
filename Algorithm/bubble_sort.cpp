#include <iostream>

using namespace std;

void swap( int*x, int* y ){
	int temp = *x;
	*x = *y;
	*y = temp;
}


bool func_less( int x, int y ){
	return x < y;
}

bool func_than( int x, int y ){
	return x > y;
}

void bubble_sort( int* a, int n ){
	for ( int i = 0; i < n - 1; i++ ){
		for ( int j = i+1; j < n; j++ ){
			if ( a[i] > a[j] )
				swap( &a[i], &a[j] );
		}
	}
}

void bubble_sort( int* a, int n, bool (*function_compare)(int,int) ){
	for ( int i = 0; i < n - 1; i++ ){
		for ( int j = i+1; j < n; j++ ){
			if ( function_compare( a[i], a[j] ) )
				swap( &a[i], &a[j] );
		}
	}
}

int main(){
	int a[] = { 2, 5, 1, 0, 8, 9, 6, 7, 10, -3 };
	int b[] = { 2, 5, 1, 0, 8, 9, 6, 7, 10, -3 };
	
	bubble_sort( a, 10 );
	bubble_sort( b, 10, func_less );
	
	cout << "INC: ";
	for ( int i = 0; i < 10; cout << a[i] << " ", i++ );
	cout << endl;
	cout << "DEC: ";
	for ( int i = 0; i < 10; cout << b[i] << " ", i++ );
	return 0;
}
