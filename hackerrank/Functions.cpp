#include <iostream>

using namespace std;

int max_of_four(int a, int b, int c, int d){
    int max = a < b ? b : a;
    max = max < c ? c : max;
    max = max < d ? d : max;
    return max; 
}

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int ans = max_of_four(a, b, c, d);
    cout << ans << endl;
    return 0;
}

