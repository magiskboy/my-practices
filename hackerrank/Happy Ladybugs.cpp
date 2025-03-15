#include <bits/stdc++.h>

using namespace std;

// Complete the happyLadybugs function below.
string happyLadybugs(string b) {
  if (b.size() == 1) {
    if (b[0] == '_')
      return "YES";
    else
      return "NO";
  }
  int chars[255];
  for (int i = 0; i < 255; ++i)
    chars[i] = 0;
  for (int i = 0; i < b.size(); ++i) {
    ++chars[(int)(b[i])];
  }
  for (int i = 64; i < 91; ++i) {
    if (chars[i] == 1)
      return "NO";
  }
  if (chars[(int)('_')] == 0) {
    for (int i = 1; i < b.size() - 1; ++i) {
      if (b[i] != b[i - 1] && b[i] != b[i + 1])
        return "NO";
    }
  }
  return "YES";
}

int main() {
  int g;
  cin >> g;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  for (int g_itr = 0; g_itr < g; g_itr++) {
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string b;
    getline(cin, b);

    string result = happyLadybugs(b);

    cout << result << "\n";
  }

  return 0;
}
