#include <bits/stdc++.h>

using namespace std;

int main(){
    vector<int> a;
    int Q1, Q2, Q3;
    int n, t;
    cin >> n;
    for ( int i = 0; i < n; i++ ){
        cin >> t;
        a.push_back(t);
    }
    sort(a.begin(), a.end());

//    for ( int i = 0; i < a.size(); i++ )
//        cout << a[i] << " ";
//    cout << "\n";

    if ( n % 2 == 1 ){
        Q2 = a[n / 2];
        vector<int> l( a.begin(), a.begin() + n / 2 );
        vector<int> u(a.begin() + n / 2 + 1, a.end());

//        for ( int i = 0; i < l.size(); i++ )
//            cout << l[i] << " ";
//        cout << "\n";
//        for ( int i = 0; i < u.size(); i++ )
//            cout << u[i] << " ";
//        cout << "\n";

        if( l.size() % 2 == 1 ){
            Q1 = l[l.size()/2];
            Q3 = u[u.size()/2];
        }
        else{
            Q1 = (l[l.size()/2-1] + l[l.size()/2]) / 2;
            Q3 = (u[u.size()/2-1] + u[u.size()/2]) / 2;
        }
    }
    else{
        Q2 = (a[n / 2 - 1] + a[n / 2]) / 2;
        vector<int> l( a.begin(), a.begin() + n / 2 );
        vector<int> u(a.begin() + n / 2, a.end());

//        for ( int i = 0; i < l.size(); i++ )
//            cout << l[i] << " ";
//        cout << "\n";
//        for ( int i = 0; i < u.size(); i++ )
//            cout << u[i] << " ";
//        cout << "\n";

        if( l.size() % 2 == 1 ){
            Q1 = l[l.size()/2];
            Q3 = u[u.size()/2];
        }
        else{
            Q1 = (l[l.size()/2-1] + l[l.size()/2]) / 2;
            Q3 = (u[u.size()/2-1] + u[u.size()/2]) / 2;
        }
    }

    cout << Q1 << "\n" << Q2 << "\n" << Q3;

    return 0;
}
