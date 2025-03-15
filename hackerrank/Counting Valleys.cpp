#include <bits/stdc++.h>

using namespace std;

// Complete the countingValleys function below.
int countingValleys(int n, string s) {
    int c = 0;
    int h = 0, h_prev = 0;
    for (int i = 0; i < n - 2; ++i){
        if (s[i] == 'U') ++h;
        else --h;
        if (h_prev == 0 && h < 0) ++c;
        h_prev = h;
    }
    return c;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    int result = countingValleys(n, s);

    fout << result << "\n";

    fout.close();

    return 0;
}
