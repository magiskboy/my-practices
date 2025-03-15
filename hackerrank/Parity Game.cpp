#include <bits/stdc++.h>

using namespace std;

int smallestSizeSubsequence(int n, vector <int> A) {
    int s = 0;
    for( int i = 0; i < A.size(); i++ ) 
           s += A[i];
    if ( s % 2 == 0 )
       return 0;
    else{
        sort(A.begin(), A.end());
        int i;
        for ( i = 0; i < A.size() && A[i] % 2 == 0; i++ );
        if ( A[i] == s )
            return -1;
        else return A[i];
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    for(int A_i = 0; A_i < n; A_i++){
       cin >> A[A_i];
    }
    int result = smallestSizeSubsequence(n, A);
    cout << result << endl;
    return 0;
}
