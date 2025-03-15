#include <bits/stdc++.h>

using namespace std;


int main(){
	int t;
	cin >> t;
	string re[t];
	string pattern = "hackerrank";
	string str;
	for ( int loop = 0; loop < t; loop++){
		cin >> str;

		int p = 0;
		for (int i = 0; i < str.length() && p < pattern.length(); i++){
			if (str[i] == pattern[p])
				p++;
		}
		if ( p == pattern.length())
			re[loop] = "YES";
		else
			re[loop] = "NO";
	}
	
	for (int  i = 0; i < t; i++)
		cout << re[i] << endl;
	
	return 0;
}