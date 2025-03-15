#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    string str;
    vector<bool> result;
    cin >> n;
    for ( int j = 0; j < n; j++ ){
        cin >> str;
        bool flag = true;
        stack<char> chr;
        int i = 0;
        while( flag && i < str.length() ){
            if ( str[i] == '(' || str[i] == '[' || str[i] == '{' ){
                chr.push( str[i] );
                i++;
            }
            else{
                if( chr.empty() ){
                    flag = false;
                }
                else if (( str[i] == ')' && chr.top() != '(' ) || ( str[i] == '}' && chr.top() != '{' ) || ( str[i] == ']' && chr.top() != '[' )){
                    flag = false;
                }
                else{
                    i++;
                    chr.pop();
                }
            }
        }
        if ( !chr.empty() )
            flag = false;

        result.push_back( flag );
    }

    for ( int i = 0; i < result.size(); i++ )
        if ( result[i] )
            cout << "YES\n";
        else
            cout << "NO\n";

    return 0;
}

