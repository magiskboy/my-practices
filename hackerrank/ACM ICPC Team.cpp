#include <iostream>

using namespace std;

int main(){
    int n, m, c;
    int topic = 0, team = 0;
    cin >> n >> m;
    string st[n];
    for(int i = 0; i < n; i++) cin >> st[i];
    for(int i = 0; i < n - 1; i++)
        for(int j = i + 1; j < n; j++){
        c = 0;
        for(int k = 0; k < m; k++)
            if(st[i][k] == '1' || st[j][k] == '1') c++;
            if(c == topic) team++;
            else if(c > topic){
            team = 1;
            topic = c;
        }
    }
    cout << topic << endl << team;
    return 0;
}