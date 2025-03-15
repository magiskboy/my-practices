#include <iostream>

using namespace std;


// using recursive
/*
bool binary_search( int* a, int begin, int end, int key ){
	if ( begin > end ){
		return false;
	}
	
	int mid = ( begin + end ) / 2;
	if ( a[mid] == key ){
		return true;
	}
	else if ( a[mid] > key ){
		return binary_search( a, begin, mid-1, key );
	}
	else{
		return binary_search( a, mid+1, end, key );
	}
}

*/

// using while loop


bool binary_search( int* a, int begin, int end, int key ){
	int mid;
	bool flag = false;
	while( begin <= end && !flag ){
		mid = ( begin + end ) / 2;
		if ( a[mid] == key ){
			flag = true;
		}
		else if ( a[mid] > key ){
			end = mid - 1;
		}
		else{
			begin = mid + 1;
		}
	}
	return flag;
}



int main(){
	int a[] = { 1, 2, 3, 4, 5, 6, 7 }; 
	cout << "Find 5: " << binary_search( a, 0, 6, 5 ) << endl;
	cout << "Find 9: " << binary_search( a, 0, 6, 9 ) << endl;
	return 0;
}
