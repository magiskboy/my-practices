#include <iostream>
using namespace std;


int g(string m[], string p[], int x, int y, int a, int b){
	for(int i = x; i < a + x; i++){
		for(int j = y; j < b + y; j++){
			if(m[i][j] != p[i-x][j-y]) return 0;
		}
	}
	return 1;
}

int f(string m[], string p[], int a, int b, int c, int d){
	for(int i = 0; i < a - c + 1; i++){
		for(int j = 0; j < b - d + 1; j++){
			if(g(m, p, i, j, c, d)) return 1;
		}
	}
	return 0;
}

int main(){
    int t;
    scanf("%d", &t);
    int x[t], a, b, c, d;
    string m[1000], p[1000];
    for(int i = 0; i < t; i++){
    	cin >> a >> b;
    	for(int i = 0; i < a; i++) cin >> m[i];
    	cin >> c >> d;
    	for(int i = 0; i < c; i++) cin >> p[i];
    	x[i] = f(m, p, a, b, c, d);
    }
    
    for(int i = 0; i < t; i++)
    if(x[i] == 1) cout << "YES" << endl;
    else cout << "NO" << endl;
    
    return 0;
}
