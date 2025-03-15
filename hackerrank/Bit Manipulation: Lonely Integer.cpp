#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    int t;  
    vector<int> a(102, 0);
    for (int i = 0; i < n ; i++){
        cin >> t;
        a[t]++;
    }
    
    for (int i = 0; i <= 100; i++)
        if ( a[i] == 1 )
            cout << i;
            exit(0);
    return 0;
}
