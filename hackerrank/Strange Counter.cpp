#include <bits/stdc++.h>

using namespace std;

// Complete the strangeCounter function below.
long strangeCounter(long t) {
  // Stupid
  if (t == 1)
    return 3;
  else if (t == 2)
    return 2;
  else if (t == 3)
    return 1;
  else if (t == 4)
    return 6;
  else if (t == 5)
    return 5;
  long rv = 0;
  long seg = (long)log2(t / 3);
  long start = 3 * (long)pow(2, seg);
  for (long i = 0; i < seg; ++i)
    t -= 3 * (long)pow(2, i);
  rv = start - t + 1;
  return rv;
}

int main() {
  long t;
  cin >> t;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  long result = strangeCounter(t);

  cout << result << "\n";

  return 0;
}
