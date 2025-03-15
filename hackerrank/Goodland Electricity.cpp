#include <bits/stdc++.h>

using namespace std;

struct point{
    point(){};
    point( int _a, int _b ){
        a = _a;
        b = _b;
        length = b-a+1;
    }
    int a, b;
    int length;
};

int compare_point( point a, point b ){
    if ( a.length == b.length )
        return 0;
    if ( a.length < b.length )
        return -1;
    return 1;
}

int main(){
	int n, k;
	cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++){
		cin >> a[i];
	}
    int tmp = 0;
    vector<point> p;
    for ( int i = 0; i < n; i++ ){
        if ( a[i] == 0 ){
            p.push_back( point(tmp, i) );
            tmp = i;
        }
    }
    
    sort(p.begin(), p.end(), compare_point);
    
    for ( int i = 0; i < p.size(); cout << p[i].a << " " << p[i].b << endl, i++ );
    
    int c = 0;
    
    for ( int i = 0; i < p.size(); i++ ){
        if ( (p[i].length / 2) > k ){
            c += a[p[i].a] == 0 ? 1 : 0;
            c += a[p[i].b] == 0 ? 1 : 0;
        }
        else
            if ( a[p[i].b] == 0 || a[p[i].a] == 0 )
                c++;
        a[p[i].a] = 1;
        a[p[i].b] = 1;
    }
    
    cout << c;

	
	return 0;
}