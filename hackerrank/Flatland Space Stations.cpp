#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the flatlandSpaceStations function below.
int flatlandSpaceStations(int n, vector<int> c) {
  int rv = 0;
  sort(c.begin(), c.end());
  for (int i = 0; i < c.size() - 1; ++i) {
    rv = max(c[i + 1] - c[i], rv);
  }
  rv = rv >> 1;

  if (c[0] > 0) {
    rv = max(rv, c[0]);
  }
  if (c[c.size() - 1] < n - 1) {
    rv = max(rv, n - 1 - c[c.size() - 1]);
  }

  return rv;
}

int main() {
  string nm_temp;
  getline(cin, nm_temp);

  vector<string> nm = split_string(nm_temp);

  int n = stoi(nm[0]);

  int m = stoi(nm[1]);

  string c_temp_temp;
  getline(cin, c_temp_temp);

  vector<string> c_temp = split_string(c_temp_temp);

  vector<int> c(m);

  for (int i = 0; i < m; i++) {
    int c_item = stoi(c_temp[i]);

    c[i] = c_item;
  }

  int result = flatlandSpaceStations(n, c);

  cout << result << "\n";

  return 0;
}

vector<string> split_string(string input_string) {
  string::iterator new_end =
      unique(input_string.begin(), input_string.end(),
             [](const char &x, const char &y) { return x == y and x == ' '; });

  input_string.erase(new_end, input_string.end());

  while (input_string[input_string.length() - 1] == ' ') {
    input_string.pop_back();
  }

  vector<string> splits;
  char delimiter = ' ';

  size_t i = 0;
  size_t pos = input_string.find(delimiter);

  while (pos != string::npos) {
    splits.push_back(input_string.substr(i, pos - i));

    i = pos + 1;
    pos = input_string.find(delimiter, i);
  }

  splits.push_back(
      input_string.substr(i, min(pos, input_string.length()) - i + 1));

  return splits;
}
