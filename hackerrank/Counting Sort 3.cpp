#include <iostream>

using namespace std;

int main(){
    string st;
    int t, n;
    int a[100];
    for(int i = 0; i < 100; i++) a[i] = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> t >> st;
        a[t]++;
    }
    cout << a[0];
    for(int i = 1; i < 100; i++){
        a[i] += a[i - 1];
        cout << " " << a[i];
    }
    return 0;
}