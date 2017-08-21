#include <iostream>

using namespace std;

bool linear_search( int* a, int n, int key ){
	bool flag = false;
	for ( int i = 0; i < n && !flag; i++ ){
		if ( a[i] == key )
			flag = true;
	}
	return flag;
}

int main(){
	int a[] = { 1, 2, 3, 4, 5, 6, 7 };
	cout << "Find 5: " << linear_search(a, 7, 5) << endl;
	cout << "Find 9: " << linear_search(a, 7, 9) << endl;
	
	return 0;
}
