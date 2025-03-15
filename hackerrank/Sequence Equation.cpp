#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

int find(vector<int> p, int value) {
  for (int i = 0; i < p.size(); ++i) {
    if (p[i] == value) {
      return i;
    }
  }
  return 0;
}

// Complete the permutationEquation function below.
vector<int> permutationEquation(vector<int> p) {
  vector<int> rv;
  int t;
  for (int i = 1; i < p.size() + 1; ++i) {
    t = find(p, i);
    t = find(p, t + 1);
    rv.push_back(t + 1);
  }
  return rv;
}

int main() {
  int n;
  cin >> n;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  string p_temp_temp;
  getline(cin, p_temp_temp);

  vector<string> p_temp = split_string(p_temp_temp);

  vector<int> p(n);

  for (int i = 0; i < n; i++) {
    int p_item = stoi(p_temp[i]);

    p[i] = p_item;
  }

  vector<int> result = permutationEquation(p);

  for (int i = 0; i < result.size(); i++) {
    cout << result[i];

    if (i != result.size() - 1) {
      cout << "\n";
    }
  }

  cout << "\n";

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
