#include <fstream>
#include <iostream>
#include <deque>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>

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

template <class T, class U>
pair<T, U> operator-( const pair<T, U>& u, const pair<T, U>& v ){
	return pair<T, U>( u.first - v.first, u.second - v.second );
}

float euclid_distance( const pi& a, const pi& b ){
	pi c = a - b;
	float distance = sqrt( pow(c.first, 2) + pow(c.second, 2) );
	return distance;
}

int mahattan_diatance( const pi& a, const pi& b ){
	pi c = a - b;
	int distance = abs(c.first) + abs(c.second);
	return distance;
}

vector< vector<int> > input(){
	fstream f( "astar.inp" );
	int m, n;
	f >> m >> n;
	v2i matrix( m, vector<int>(n) );
	for ( int i = 0; i < m; i++ )
	for ( int j = 0; j < n; f >> matrix[i][j], j++ );

	return matrix;
}

vector<pi> astar( v2i matrix, pi s, pi f, float(*func_distance)(const pi& a, const pi& b) ){
	priority_queue< pi > q;
	int m = matrix.size();
	int n = matrix[0].size();
	v2b mark( m, vector<bool>(n, true) );
	v2b in_queue( m, vector<bool>(n, false) );
	v2p trace( m, vector<pi>(n) );
	vector<pi> path;
	bool flag = false;

	q.push(s);

	while ( !q.empty() && !flag ){
		pi tmp = q.top();
		q.pop();
		mark[tmp.first][tmp.second] = false;

		if ( tmp == f ){
			flag = true;
		}
		else{
			for ( int i = 0; i < 4; i++ ){
				pi next = tmp + direction[i];
				if ( next.first >= 0 && next.first < m && next.second >= 0 && next.second < n
					&& mark[next.first][next.second] && matrix[next.first][next.second]
					&& !in_queue[next.first][next.second] ){
						q.push(next);
						in_queue[next.first][next.second] = true;
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

	vector<pi> path(0);
	path = astar(matrix, pi(0,0), pi(1,4), euclid_distance);
	if ( path.size() > 0 ){
		for ( int i = 0; i < path.size(); cout << "(" << path[i].first << ", " << path[i].second << ")-> ", i++ );
	}
	else{
		cout << "Couldn't path";
	}

	return 0;
}
