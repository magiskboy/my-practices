#include <iostream>

using namespace std;

int main(){
    int t;
    cin >> t;
    int x[t], y[t];
    int n, m;
    for ( int loop = 0; loop < t; loop++ ){
        cin >> m >> n;
        int a[n];
        x[loop] = y[loop] = 0;
        for ( int i = 0; i < n; i++ )
            cin >> a[i];
        for( int i = 0; i < n - 1 && x[loop] == 0 && y[loop] == 0; i++ ){
            for ( int j = i+1; j < n; j++ )
                if ( a[i] + a[j] <= m ){
                    x[loop] = i+1;
                    y[loop] = j+1;
                    break;
                }
        }
    }
    
    for ( int i = 0; i < t; i++ )
        cout << x[i] << " " << y[i] << endl;
    return 0;
}