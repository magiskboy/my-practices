#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int f(int i, int j, string grid[]){
	if(grid[i][j] <= grid[i][j-1]) return 0;
	if(grid[i][j] <= grid[i][j+1]) return 0;
	if(grid[i][j] <= grid[i-1][j]) return 0;
	if(grid[i][j] <= grid[i+1][j]) return 0;
	return 1;
}

int main(){
    int n;
    cin >> n;
    string grid[n + 2];
    for(int i = 1; i < n + 1; i++) cin >> grid[i]; 
    
    for(int i = 0; i < n + 2; i++){
        grid[0] += 'a';
        grid[n + 1] += 'a';
    }
    for(int i = 1; i < n + 1; i++){
    	grid[i] = 'a' + grid[i] + 'a';
    }
    
    for(int i = 1; i < n + 1; i++)
    for(int j = 1; j < n + 1; j++)
    if(f(i, j, grid)) grid[i][j] = 'X';
    
    for(int i = 1; i < n + 1; i++){
    	for(int j = 1; j < n + 1; j++) cout << grid[i][j];
    	cout << endl;
    }
    
    return 0;
}
