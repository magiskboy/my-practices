#include <iostream>

using namespace std;

int main(){
    int t, n, c, m;
    cin >> t;
    int x[t];
    for(int i = 0; i < t; i++){
    	cin >> n >> c >> m;
    	int k = n / c;
    	x[i] = k;
    	while(k >= m){
    		x[i] += k / m;
    		k = k / m + k % m;
    	}
    }
    for(int i = 0; i < t; i++) cout << x[i] << endl;
    
    return 0;
}
