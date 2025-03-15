#include <bits/stdc++.h>

using namespace std;

bool check( int a ){
    bool flag = true;
    int c1 = 0, c2 = 0;
    for ( int i = 2; i <= a/2; i++ )
        if ( a % i == 0 )
            c1++;
    for ( int i = 2; i <= (a+1)/2; i++ )
        if ( (a+1) % i == 0 )
            c2++;
    if ( c1 != c2 )
        flag = false;
    return flag;
}

int main(){
    int n;
    cin >> n;
    int c[n];
    for ( int i = 0; i < n; i++ ){
        int a;
        cin >> a;
        c[i] = 0;
        for ( int j = 2; j < a; j++ )
            if( check(j) )
                c[i]++;
    }

    for ( int i = 0; i < n; i++ )
        cout << c[i] << "\n";


    return 0;
}
