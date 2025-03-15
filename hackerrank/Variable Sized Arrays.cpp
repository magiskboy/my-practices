#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


int main() {
    vector<vector<int>> arr;
    vector<int> r;
    int n, q;
    int k;
    
    cin >> n >> q;
    for (int i = 0; i < n; i++){
        int tmpN;
        int tmpV;
        cin >> tmpN;
        vector<int> tmpVec;
        for (int j = 0; j < tmpN; j++){
            cin >> tmpV;
            tmpVec.push_back(tmpV);
        }
        arr.push_back(tmpVec);
    }
    
    for (int i = 0; i < q; i++){
        int tmpI, tmpQ;
        cin >> tmpI >> tmpQ;
        r.push_back(arr[tmpI][tmpQ]);
    }
    
    for (int i = 0; i < r.size(); i++)
        cout << r[i] << endl;
    
    return 0;
}
