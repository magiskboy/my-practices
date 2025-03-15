#include <iostream>
#include <math.h>

using namespace std;

int main(){
    
    string st;
    getline(cin, st);
    int p = 0;
    while(p < st.size()){
    	if(st[p] == ' ') st.erase(p, 1);
    	else p++;
    }
    int a = (int)sqrt(st.size());
    if(a * a != st.size()) a++;
    
    string st2[a];
    p = 0;
    for(int i = 0; i < st.size(); i++){
    	st2[p] += st[i];
    	if(++p == a) p = 0;
    }
    
    for(int i = 0; i < a; i++) cout << st2[i] << " ";
    
    return 0;
}
