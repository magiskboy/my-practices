#include <iostream>

using namespace std;

bool less_func( int x, int y ){
	return x < y;
}

bool than_func( int x, int y ){
	return x > y;
}

void insert_sort( int* a, int n, bool(*func_compare)(int,int) ){
	for ( int i = 1; i < n; i++ ){
		int k = i-1;
		int temp = a[i];
		while ( k >= 0 && !(func_compare)(temp, a[k]) ){
			a[k+1] = a[k];
			k--;
		}
		a[k+1] = temp;
	}
}


int main(){
	int a[] = { 2, 5, 1, 0, 8, 9, 6, 7, 10, 3 };
	int b[] = { 2, 5, 1, 0, 8, 9, 6, 7, 10, 3 };
	
	insert_sort( a, 10, less_func );
	insert_sort( b, 10, than_func );
	
	cout << "DESC: ";
	for ( int i = 0; i < 10; cout << a[i] << " ", i++ );
	cout << endl;
	cout << "INC: ";
	for ( int i = 0; i < 10; cout << b[i] << " ", i++ );
	
	return 0;
}
