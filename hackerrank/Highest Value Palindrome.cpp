#include <bits/stdc++.h>

using namespace std;

int main(){
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	
	map< int, map<char, char> > d;
	
	for ( int i = 0; i < s.length() / 2; i++ ){
		if ( s[i] != s[s.length() - 1 - i] ){
			map<char, char> tmp;
			tmp.insert(pair<char, char>(s[i], s[s.length()-i-1]));
			d.insert(pair<int, map<char, char> >(i, tmp));
		}
	}
	
	if ( d.size() > k )
		cout << "-1";
	else{
		for ( map< int, map<char, char> >::iterator it = d.begin(); it != d.end(); it++ ){
			map<char, char>::iterator tmp = it->second.begin();
			int i = it->first;
			if ( tmp->first > tmp->second )
				s[s.length()-i-1] = tmp->first;
			else
				s[i] = tmp->second;
				
			k--;
		}
		
		for ( map< int, map<char, char> >::iterator it = d.begin(); it != d.end() && k > 0; it++ ){
			int i = it->first;
			if ( s[i] != '9' ){
				s[i] = s[s.length()-i-1] = '9';
				k--;
			}
		}
		
		for ( int i = 0; i < s.length()/2 && k >= 2; i++ ){
			if ( s[i] != '9' ){
				s[i] = s[s.length()-i-1] = '9';
				k -= 2;
			}
		}
		
		if ( k > 0 ){
            if( s.length() % 2 == 1 )
                s[s.length()/2] = '9';
        }
		
		cout << s;
	}
	
	return 0;
}