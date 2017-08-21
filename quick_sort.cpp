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

void quick_sort( int* a, int begin, int end, bool (*func_compare)(int,int) ){
	if ( begin < end ){
		int mid = a[(begin + end) / 2];
		int i = begin;
		int j = end;
		
		do{
			while ( func_compare(a[i], mid) )
				i++;
			while( !(func_compare(a[j], mid)) && a[i] != a[j] )
				j--;
			if ( i <= j ){
				swap( &a[i], &a[j] );
				i++;
				j--;
			}
			
		} while ( i < j );
		
		quick_sort( a, begin, j, func_compare );
		quick_sort( a, i, end, func_compare );
	}
}

int main(){
	int a[] = { 2, 5, 1, 0, 8, 9, 6, 7, 10, -3 };
	int b[] = { 2, 5, 1, 0, 8, 9, 6, 7, 10, -3 };
	
	quick_sort( a, 0, 9, func_less );
	quick_sort( b, 0, 9, func_than );
	
	cout << "DESC: ";
	for ( int i = 0; i < 10; cout << a[i] << " ", i++ );
	cout << endl;
	cout << "INC: ";
	for ( int i = 0; i < 10; cout << b[i] << " ", i++ );
	
	return 0;
}
