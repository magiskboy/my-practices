#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int find( int *arr, int size, int n ){
    if ( n <= arr[0] )
        return arr[0]-n;
    if ( n >= arr[size-1] )
        return n - arr[size-1];
    for ( int i = 0; i < size; i++ )
        if ( arr[i] == n )
            return 0;
        else if( arr[i] > n )
            return min(arr[i] - n, n - arr[i-1]);
    
    return -1;
}


int main() {
    int n, p, q;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cin >> p >> q;
    sort(a , a+n);
    int result;
    int max = -9999;
    for ( int i = p; i <= q; i++ ){
        int tmp = find(a, n, i);
        if ( tmp > max ){
            max = tmp;
            result = i;
        }
    }
    
    cout << result;
    
    return 0;       
}
