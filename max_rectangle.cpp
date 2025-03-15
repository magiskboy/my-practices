// Given a 2D array, find the maximum sum subarray in it

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

vector< vector<int> > input(){
	fstream f("max_rectangle.inp", ios::in);
	int m, n;
	f >> m >> n;
	vector< vector<int> > matrix( m, vector<int>(n) );
	for ( int i = 0; i < m; i++ )
	for ( int j = 0; j < n; f >> matrix[i][j], j++ );
	return matrix;
}

int findMax1D( int* a, int n, int* start, int* finish ){
	int sumMax = -99999;
	int sum = 0;
	*start = 0;
	*finish = -1;
	for ( int i = 0; i < n; i++ ){
		if ( a[i] < 0 ){
			if ( sum > sumMax ){
				sumMax = sum;
				*finish = i-1;
			}
		}
		else{
			sum += a[i];
		}
	}
	return sumMax;
}



int main(){
	vector< vector<int> > matrix = input();
	int a[] = { 1, 2, -3, -4, 5, -6 };
	int s, f;
	cout << findMax1D(a, 6, &s, &f);
	cout << endl << s << " " << f;
	
	return 0;
}
