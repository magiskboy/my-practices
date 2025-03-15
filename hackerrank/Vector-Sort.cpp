#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    int t;
    for ( int i = 0; i < n; i++ )
        cin >> v[i];
    
    sort(v.begin(), v.end());
    
    for ( int i = 0; i < n; cout << v[i] << " ", i++ );
    return 0;
}
