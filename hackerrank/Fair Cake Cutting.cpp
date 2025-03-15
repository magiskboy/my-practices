#include <bits/stdc++.h>

using namespace std;

long howManyToInvite(long A, long B, long a) {
    return int(a / ((float)A / B));
}

int main() {
    long A;
    long B;
    long a;
    cin >> A >> B >> a;
    long b = howManyToInvite(A, B, a);
    cout << b << endl;
    return 0;
}
