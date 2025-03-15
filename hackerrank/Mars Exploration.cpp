#include <iostream>

using namespace std;

int f(string st){
	int c = 0;
	if(st[0] != 'S') c++;
	if(st[1] != 'O') c++;
	if(st[2] != 'S') c++;
	return c;
}

int main(){
	string st;
	getline(cin, st);
	int s = st.size() / 3, c = 0;
	for(int i = 0; i < s; i++){
		c += f(st.substr(3 * i, 3));
	}
	cout << c;
	return 0;
}