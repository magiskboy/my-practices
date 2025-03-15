#include <fstream>
#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector< vector<int> > v2i;
typedef vector< vector<bool> > v2b;
typedef vector< vector< pair<int, int> > > v2p;
typedef pair<int, int> pi;

const pi direction[] = { pi(0, 1), pi(0, -1), 
									 pi(1, 0), pi(-1, 0) };

template <class T, class U>
pair<T, U> operator+( const pair<T, U>& u, const pair<T, U>& v ){
	return pair<T, U>( u.first + v.first, u.second + v.second );
}

vector< vector<int> > input(){
	fstream f( "bfs.inp" );
	int m, n;
	f >> m >> n;
	v2i matrix( m, vector<int>(n) );
	for ( int i = 0; i < m; i++ )
	for ( int j = 0; j < n; f >> matrix[i][j], j++ );
	
	return matrix;
}

vector<pi> bfs( v2i matrix, pi s, pi f ){
	deque< pi > st;
	int m = matrix.size();
	int n = matrix[0].size();
	v2b mark( m, vector<bool>(n, true) );
	v2p trace( m, vector<pi>(n) );
	vector<pi> path;
	bool flag = false;
	
	st.push_front(s);
	
	while ( !st.empty() && !flag ){
		pi tmp = st.front();
		st.pop_front();
		mark[tmp.first][tmp.second] = false;
		
		if ( tmp == f ){
			flag = true;
		}
		else{
			for ( int i = 0; i < 4; i++ ){
				pi next = tmp + direction[i];
				if ( next.first >= 0 && next.first < m && next.second >= 0 && next.second < n
					&& mark[next.first][next.second] && matrix[next.first][next.second] && !binary_search(st.begin(), st.end(), next) ){
						st.push_back(next);
						trace[next.first][next.second] = tmp;
					}
			}
		}
	}

	if ( flag ){
		pi tmp = f;
		while ( tmp != s ){
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
	
	vector<pi> path = bfs(matrix, pi(0,0), pi(4,4));
	if ( path.size() > 0 ){
		for ( int i = 0; i < path.size(); cout << "(" << path[i].first << ", " << path[i].second << ")-> ", i++ );
	}
	else{
		cout << "Couldn't path";
	}
	
	return 0;
}
