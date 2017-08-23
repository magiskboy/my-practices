#include <iostream>

using namespace std;

void merge_sort( int* a, int* b, int* arr_sorted, int m, int n ){
	int i = 0, j = 0, k = 0;
	while ( i < m && j < n ){
		if ( a[i] < b[j] )
			arr_sorted[k++] = a[i++];
		else
			arr_sorted[k++] = b[j++];
	}
	
	for ( ; i != m; arr_sorted[k++] = a[i++] );
	for ( ; j != n; arr_sorted[k++] = b[j++] );
}

int main(){
	int a[] = { 1, 3, 8, 10, 15 };
	int b[] = { 2, 4, 4, 6, 7, 8, 10 };
	int arr_sorted[12];
	merge_sort( a, b, arr_sorted, 5, 7 );
	
	cout << "Array sorted: ";
	for ( int i = 0; i < 12; cout << arr_sorted[i] << " ", i++ );
	
	return 0;
}
