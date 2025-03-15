#include <bits/stdc++.h>

using namespace std;


int main(){
	string str;
	bool flag = true;
	getline(cin, str);
	
	if (str.length() < 26)
		flag = false;
	else{	
		for (int i = 0; i < str.length(); i++) 
			str[i] = tolower(str[i]);
		for (int i = 97; i <= 122 && flag; i++)
			if (str.find(char(i)) == string::npos)	
				flag = false;
	}

	if (flag)
		cout << "pangram\n";
	else 
		cout << "not pangram\n";

	return 0;
}