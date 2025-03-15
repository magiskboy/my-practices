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

int find_value( int* a, int begin, int end, bool (*func_compare)(int,int) ){
	int pos = -1;
	int value = a[begin];
	for ( int i = begin+1; i <= end; i++ ){
		if ( func_compare(value, a[i]) ){
			value = a[i];
			pos = i;
		}
	}	
	return pos;
}

void select_sort( int* a, int n, bool (*func_compare)(int,int) ){
	for ( int i = 0; i < n - 1; i++ ){
		int pos = find_value( a, i, n-1, func_compare );
		if ( pos != -1 ){
			swap( &a[i], &a[pos] );
		}
	}
}

int main(){
	int a[] = { 2, 5, 1, 0, 8, 9, 6, 7, 10, -3 };
	int b[] = { 2, 5, 1, 0, 8, 9, 6, 7, 10, -3 };
	
	select_sort( a, 10, func_less );
	select_sort( b, 10, func_than );
	
	cout << "DESC: ";
	for ( int i = 0; i < 10; cout << a[i] << " ", i++ );
	cout << endl;
	cout << "INC: ";
	for ( int i = 0; i < 10; cout << b[i] << " ", i++ );
	
	return 0;
}
