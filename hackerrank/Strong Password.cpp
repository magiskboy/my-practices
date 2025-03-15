#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'minimumNumber' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. STRING password
 */

int minimumNumber(int n, string password) {
    string numbers = "0123456789";
    string lower_case = "abcdefghijklmnopqrstuvwxyz";
    string upper_case = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string special_characters = "!@#$%^&*()-+";
    
    bool has_number = false;
    bool has_lower = false;
    bool has_upper = false;
    bool has_special = false;

    for (int i = 0; i < n; ++i) {
        char ch = password[i];
        if (!has_number && numbers.find(ch) != string::npos) has_number = true;
        if (!has_lower && lower_case.find(ch) != string::npos) has_lower = true;
        if (!has_upper && upper_case.find(ch) != string::npos) has_upper = true;
        if (!has_special && special_characters.find(ch) != string::npos) has_special = true;
        
        if (has_special && has_lower && has_number && has_upper) break;
    }
    
    int c = 0;
    if (!has_number) ++c;
    if (!has_lower) ++c;
    if (!has_special) ++c;
    if (!has_upper) ++c;
    
    if (n >= 6) return c;
    
    int r = 6 - n;
    cout << r << " " << c;
    return c < r ? r : c;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string password;
    getline(cin, password);

    int answer = minimumNumber(n, password);

    fout << answer << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
