#include <bits/stdc++.h>
using namespace std;


int main() {
    int n;
    cin >> n;
    double mean = 0.f;
    int a[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
        mean += a[i];
    }
    
    mean /= (double)n;
    double s = 0.f;
    for (int i = 0; i < n; i++){
        s += pow(a[i]-mean, 2); 
    }
    
    cout << setprecision(1) << fixed << sqrt(s/(double)n);
    
    return 0;
}
