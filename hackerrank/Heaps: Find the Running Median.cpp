#include <bits/stdc++.h>

using namespace std;

int main(){
    vector<int> a;
    vector<float> b;
    int n, t;
    cin >> n;
    for ( int i = 0; i < n; i++ ){
        cin >> t;
        a.push_back(t);
        sort(a.begin(), a.end());
        if ( a.size() % 2 == 0 ){
            float t = (a[a.size()/2-1] + a[a.size()/2]) / 2.f;
            b.push_back(t);
        }
        else
            b.push_back(a[a.size() / 2]);
    }

    for ( int i = 0; i < b.size(); i++ )
        cout << setprecision(1) << fixed << b[i] << "\n";

    return 0;
}
