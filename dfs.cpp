#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
#include <fstream>

using namespace std;

typedef vector< vector<int> > v2i;
typedef vector< vector<bool> > v2b;
typedef vector< vector< pi > > v2p;
typedef pi pi;

const pi direction[] = { pi(1, 0), pi(-1, 0), pi(0, 1), pi(0, -1) };

template <class T, class U>
pair<T, U> operator+( const pair<T, U>& u, const pair<T, U>& v ){
	return pair<T, U>( u.first + v.first, u.second + v.second );
}

v2i input(){
	fstream f("dfs.inp", ios::in);
	if ( f.is_open() ){
		int m, n;
		f >> m >> n;
		v2i matrix( m, vector<int>(n) );
		for ( int i = 0; i < m; i++ )
		for ( int j = 0; j < n; f >> matrix[i][j], j++ );
		
		return matrix;
	}
	else{
		cout << "Can'n open file" << endl;
	}
}

vector<pi> dfs( v2i matrix, pi s, pi f ){
	deque<pi> q;
	bool flag = false;
	int m = matrix.size();
	int n = matrix[0].size();
	v2b mark( m, vector<bool>(n, true) );
	v2p trace( m, vector< pi >(n) );
	vector< pi > path;
	
	
	q.push_front(s);
	
	while ( !flag && !q.empty() ){
		pi tmp = q.front();
		q.pop_front();
		mark[tmp.first][tmp.second] = false;
		
		if ( tmp == f ){
			flag = true;
		}
		else{
			for ( int i = 0; i < 4; i++ ){
				pi next = tmp + direction[i];
				if ( next.first >= 0 && next.first < m && next.second >= 0 
					&& next.second < n && matrix[next.first][next.second] 
					&& mark[next.first][next.second] && !binary_search(q.begin(), q.end(), next) ){
						q.push_front(next);
						trace[next.first][next.second] = tmp;
					}
			}
		}
		
	}
	
	if ( flag ){
		pi tmp = f;
		while( tmp != s ){
			path.push_back(tmp);
			tmp = trace[tmp.first][tmp.second];
		}
		path.push_back(s);
	}
	reverse(path.begin(), path.end());
	
	return path;
}

int main(){
	v2i matrix = input();
	vector< pi > path = dfs( matrix, pi(0, 0), pi(1, 4) );
	
	for ( int i = 0; i < path.size(); cout << "(" << path[i].first << ", " << path[i].second << ")-> ", i++ );
	
	return 0;
}

