#include <bits/stdc++.h>

using namespace std;

bool validate( string &str ){
	for ( int i = 0; i < str.length()-1; i++ )
		if ( str[i] == str[i+1])
			return false;
	return true;
}

string get( char ch1, char ch2, string& str ){
	string result;
	for (int i = 0; i < str.length(); i++)
	if (str[i] == ch1 || str[i] == ch2)
		result += str[i];
	return result;
}

int main(){
    int n;
	string str, sort_str;
	string character;
	
	cin >> n >> str;	
	sort_str = str;
	sort(sort_str.begin(), sort_str.end());
	for ( int i = 0; i < sort_str.length()-1; ){
		if (sort_str[i] == sort_str[i+1]){
			sort_str.erase(i, 1);
		}
		else
			i++;
	}
	
	int cmax = 0;
	for ( int i = 0; i < sort_str.length(); i++)
	for ( int j = 0; j < sort_str.length(); j++)
	if (i != j){
		string tmp = get( sort_str[i], sort_str[j], str );
		if (tmp.length() > cmax && validate(tmp))
			cmax = tmp.length();
	}

	cout << cmax << endl;
	

	
	return 0;
}