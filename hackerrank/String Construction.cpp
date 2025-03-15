#include <iostream>

using namespace std;

int main(){
	int t;
	cin >> t;
	string st, st2;
	int x[t];
	for(int i = 0; i < t; i++){
		cin >> st;
		x[i] = 1;
		st2 = st[0];
		st.erase(0, 1);
		while(st.size() > 0){
			int p = st.find(st2);
			if(p != 0){
				st2 += st[0];
				st.erase(0, 1);
				x[i]++;
			}
			else{
				int k = st2.size();
				st2 += st.substr(0, st2.size());
				st.erase(0, k);
			}
		}
		
	}
	for(int i = 0; i < t; i++) cout << x[i] << endl;
	return 0;
}