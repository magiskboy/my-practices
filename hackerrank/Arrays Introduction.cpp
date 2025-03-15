#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


int main() {
    int n, t;
    vector<int> arr;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> t;
        arr.push_back(t);
    }
    reverse(arr.begin(),arr.end());
    
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    return 0;
}
