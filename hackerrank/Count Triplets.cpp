#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

long long factorial(int n) {
    long long r = 1;
    for (int i = 2; i < n + 1; ++i) r *= i;
    return r;
} 

long C(int n, int r) {
    long s = 1;
    for (int i = n-r+1; i < n + 1; ++i) s *= i;
    return s / factorial(r);
}

// Complete the countTriplets function below.
long countTriplets(vector<long> arr, long r) {
    long ret = 0;
    map<long, int> m;
    for (vector<long>::iterator it = arr.begin(); it != arr.end(); ++it) {
        if (m.find(*it) != m.end()) {
            ++m[*it];
        } else {
            m[*it] = 1;
        }
    }
    
    vector<long> keys;
    for (map<long, int>::iterator it = m.begin(); it != m.end(); ++it) {
        keys.push_back(it->first);
    }
    
    sort(keys.begin(), keys.end());
    int keys_len = keys.size();
    
    if (keys_len == 1 && r == 1) {
        return C(arr.size(), 3);
    }
    
    for (int i = 0; i < keys_len - 2; ++i) {
        if (keys[i] * r == keys[i+1] && keys[i+1] * r == keys[i+2]) {
            ret += m[keys[i]] * m[keys[i+1]] * m[keys[i+2]];
        }
    }
    
    return ret;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nr_temp;
    getline(cin, nr_temp);

    vector<string> nr = split(rtrim(nr_temp));

    int n = stoi(nr[0]);

    long r = stol(nr[1]);

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<long> arr(n);

    for (int i = 0; i < n; i++) {
        long arr_item = stol(arr_temp[i]);

        arr[i] = arr_item;
    }

    long ans = countTriplets(arr, r);

    fout << ans << "\n";

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
