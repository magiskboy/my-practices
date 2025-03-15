#include <iostream>

using namespace std;

int main(){
    int n, x;
    cin >> n;
    int r[n];
    for (int i = 0; i < n; ++i){
        cin >> x;
        int k = 5 - x % 5;
        if (x+k < 40 || k >= 3) r[i] = x;
        else r[i] = x + k;
    }
    for (int i = 0; i < n; ++i) cout << r[i] << endl;

    return 0;
}
