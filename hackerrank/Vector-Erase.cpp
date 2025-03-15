#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n, x, a, b;
    cin >> n;
    vector<int> v(n);
    for ( int i = 0; i < n; cin >> v[i], i++ );
    cin >> x >> a >> b;
    v.erase(v.begin()+x-1);
    v.erase(v.begin()+a-1, v.begin()+b-1);
    cout << v.size() << endl;
    for ( int i = 0; i < v.size(); cout << v[i] << " ", i++ );
    return 0;
}
