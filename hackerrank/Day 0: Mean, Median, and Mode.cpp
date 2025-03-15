#include <bits/stdc++.h>

using namespace std;

int getMaxMode(int *a,  int n){
    int max_mode = 0;
    int num_max_mode = a[0];
    int c = 1;
    for ( int i = 1; i < n; i++ ){
        if ( a[i] == a[i-1] )
            c++;
        else{
            if ( max_mode < c ){
                max_mode = c;
                num_max_mode = a[i-1];
            }
            c = 1;
        }
    }
    return num_max_mode;
}


int main() {
    int n, s = 0;
    double mean, med, mode;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
        mean += a[i];
    }
    
    mean /= (double)n;
    
    sort(a, a+n);
    
    if ( n % 2 == 1 )
        med = a[n/2];
    else
        med = (a[n/2-1] + a[n/2])/2.f;
    
    mode = getMaxMode(a, n);
    
    cout << setprecision(1) << fixed << mean << endl << med << endl; 
    cout << setprecision(0) << mode;
 
    return 0;
}
