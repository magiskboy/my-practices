#include <bits/stdc++.h>

using namespace std;

// Complete the appendAndDelete function below.
string appendAndDelete(string s, string t, int k) {
    int cl = 0;
    for (int i = 0; i < min(s.size(), t.size()); ++i) {
        if (s[i] == t[i]) {
            ++cl;
        }
        else {
            break;
        }
    }

    if (s.size() + t.size() <= k) {
        return "Yes";
    }
    else if (t.size() + s.size() - 2 * cl > k) {
        return "No";
    }
    else if ((t.size() + s.size()) % 2 == k % 2) {
        return "Yes";
    }
    else {
        return "No";
    }
}

int main()
{
    string s;
    getline(cin, s);

    string t;
    getline(cin, t);

    int k;
    cin >> k;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string result = appendAndDelete(s, t, k);

    cout << result << "\n";

    return 0;
}
