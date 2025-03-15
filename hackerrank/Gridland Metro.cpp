#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

struct point{
    int x, y;
    point(){
        x = 0;
        y = 0;
    }
    point(int _x, int _y ){
        x = _x;
        y = _y;
    }
};

int abs_n( int n ){
    return n < 0 ? -n : n;
}

bool compare_point( point a, point b ){
    if ( a.x < b.x )
        return true;
    else if ( a.x > b.x )
        return false;
    else{
        if ( a.y-a.x < b.y-b.x )
            return true;
        else if (a.y-a.x > b.y-b.x)
            return true;
        else 
            return false;
    }
}

int main(){
    int n, m, k;
    map<int, vector<point> > d;
    cin >> n >> m >> k;
    long long s = n * m;
    int a, b, c;
    for ( int i = 0; i < k; i++ ){
        cin >> a >> b >> c;
        if ( d.count(a) <= 0 ){ 
            vector<point> t;
            t.push_back(point(b, c));
            d.insert( pair<int, vector<point> >(a, t) );
        }
        else{
            d[a].push_back(point(b, c));
        }
    }
    
    for ( map<int, vector<point> >::iterator it = d.begin(); it != d.end(); it++ ){
        vector<point> tmp = it->second;
        sort(tmp.begin(), tmp.end(), compare_point);
        
        int tmps = tmp[0].y - tmp[0].x + 1;
        for ( int i = 1; i < tmp.size(); i++ ){
        	if ( tmp[i].y <= tmp[i-1].y ){}
            else if ( tmp[i].x < tmp[i-1].y ){
                tmps += tmp[i].y - tmp[i-1].y;
            }
            else if ( tmp[i].y == tmp[i-1].y ){
            	tmps += tmp[i].y - tmp[i].x;
            }
            else{
                tmps += tmp[i].y - tmp[i].x + 1; 
            }
        }
        s -= tmps;

    }
    
    s = s < 0 ? 0 : s;
    
    cout << s;
    
    return 0;
}