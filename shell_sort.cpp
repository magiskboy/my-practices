#include <iostream>

using namespace std;

bool less_func( int x, int y ){
	return x < y;
}

bool than_func( int x, int y ){
	return x > y;
}

void shell_sort( int* a, int n, bool(*func_compare)(int,int) ){
//	in insert sort, h = 1;	
	int h = n / 2;
	while ( h != 0 ){
		for ( int i = h; i < n; i++ ){
			int temp = a[i];
			int j = i - h;
			while ( j >= 0 && !(func_compare(temp, a[j])) ){
				a[j+h] = a[j];
				j -= h;
			}
			a[j+h] = temp;
		}
		h /= 2;
	}
}


int main(){
	int a[] = { 2, 5, 1, 0, 8, 9, 6, 7, 10, 3 };
	int b[] = { 2, 5, 1, 0, 8, 9, 6, 7, 10, 3 };
	
	shell_sort( a, 10, less_func );
	shell_sort( b, 10, than_func );
	
	cout << "DESC: ";
	for ( int i = 0; i < 10; cout << a[i] << " ", i++ );
	cout << endl;
	cout << "INC: ";
	for ( int i = 0; i < 10; cout << b[i] << " ", i++ );
	
	return 0;
}
