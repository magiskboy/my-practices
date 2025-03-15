#include <bits/stdc++.h>

using namespace std;

// Complete the superReducedString function below.
string superReducedString(string s) {
    stack<char> st;
    st.push(s[0]);
    for (int i = 1; i < s.size(); ++i) {
        if (!st.empty() && st.top() == s[i]) {
            st.pop();
        }
        else {
            st.push(s[i]);
        }
    }
    if (st.empty()) return "Empty String";
    string rv;
    while (!st.empty()) {
        rv += st.top();
        st.pop();
    }
    reverse(rv.begin(), rv.end());
    return rv;
}

int main()
{
    string s;
    getline(cin, s);

    string result = superReducedString(s);

    cout << result << "\n";

    return 0;
}
