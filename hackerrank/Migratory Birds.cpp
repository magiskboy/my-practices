#include <bits/stdc++.h>

using namespace std;

int migratoryBirds(int n, vector <int> ar) {
    int a[6];
    a[1] = 0;
    a[2] = 0;
    a[3] = 0;
    a[4] = 0;
    a[5] = 0;
    
    for ( int i = 0; i < ar.size(); i++ ) 
        a[ar[i]]++; 
    int _max = a[1];
    int imax = 1;
    for ( int i = 2; i <= 5; i++ )
        if (a[i] > _max){
            _max = a[i];
            imax = i;
        }
    return imax;
}

int main() {
    int n;
    cin >> n;
    vector<int> ar(n);
    for(int ar_i = 0; ar_i < n; ar_i++){
       cin >> ar[ar_i];
    }
    int result = migratoryBirds(n, ar);
    cout << result << endl;
    return 0;
}
