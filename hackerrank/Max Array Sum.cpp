#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  int a[n + 1];
  int s[n + 1];
  a[0] = 0;
  for (int i = 0; i < n; ++i)
    cin >> a[i + 1];

  s[0] = a[0];
  s[1] = a[1];
  for (int i = 2; i < n + 1; ++i) {
    s[i] = max(max(s[i - 1], a[i] + s[i - 2]), a[i]);
  }

  cout << s[n];
  return 0;
}
