#include <bits/stdc++.h>

using namespace std;

// Complete the weightedUniformStrings function below.
vector<string> weightedUniformStrings(string s, vector<int> queries) {
    set<int> ss;
    char prev = s[0];
    int t = (int)prev - 97 + 1;
    ss.insert(t);

    for (int i = 1; i < s.size(); ++i) {
        if (s[i] != prev) {
            t = (int)s[i] - 97 + 1;
            prev = s[i];
        }
        else {
            t += (int)s[i] - 97 + 1;
        }
        cout << s[i] << " " << t << endl;
        ss.insert(t);
    }
    ss.insert(t);

    vector<string> ret;
    for (vector<int>::iterator it = queries.begin(); it != queries.end(); it++) {
        if (ss.find(*it) != ss.end()) {
            ret.push_back("Yes");
        }
        else {
            ret.push_back("No");
        }
    }
    return ret;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    int queries_count;
    cin >> queries_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> queries(queries_count);

    for (int i = 0; i < queries_count; i++) {
        int queries_item;
        cin >> queries_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        queries[i] = queries_item;
    }

    vector<string> result = weightedUniformStrings(s, queries);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}
