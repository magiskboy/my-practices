#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

/*
 * Complete the indianJob function below.
 */
string indianJob(int g, vector<int> a) {
    int n = a.size();
    sort(a.begin(), a.end(), greater<int>());
    int i = 0;
    while (i < n - 1 && g > 0) {
        if (a[i+1] < a[i])
            swap(a[i], a[i+1]);
        g -= a[i];
        a[i+1] -= a[i];
        a[i] = 0;
        if (a[i+1] == 0) {
            i += 2;
        }
        else {
            i += 1;
        }
    }

    if (accumulate(a.begin(), a.end(), 0) > g)
        return "NO";
    else
        return "YES";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string ng_temp;
        getline(cin, ng_temp);

        vector<string> ng = split_string(ng_temp);

        int n = stoi(ng[0]);

        int g = stoi(ng[1]);

        string arr_temp_temp;
        getline(cin, arr_temp_temp);

        vector<string> arr_temp = split_string(arr_temp_temp);

        vector<int> arr(n);

        for (int arr_itr = 0; arr_itr < n; arr_itr++) {
            int arr_item = stoi(arr_temp[arr_itr]);

            arr[arr_itr] = arr_item;
        }

        string result = indianJob(g, arr);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

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

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
