#include <iostream>
 
using namespace std;
typedef long long ll;
 
 
int main(){
    string s;
    cin >> s;
    ll n;
    ll count=0;
    cin >> n;
    for(ll i=0;i<s.size();i++){
        if(s[i] == 'a')
            count++;
    }
    ll ans =0 ;
    ans = n/s.size();
    ans*=count;
    if((n%s.size())){
        ll r = n%s.size();
        for(ll i=0;i<r;i++){
            if(s[i] == 'a') ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}