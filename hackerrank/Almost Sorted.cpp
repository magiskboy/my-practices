#include <bits/stdc++.h>

int main() {
    int n;
    std::cin >> n;
    int a[n], b[n];
    for ( int i = 0; i < n; std::cin >> a[i], b[i] = a[i], i++ );
    
    std::sort(b, b+n);
    
    std::vector<int> c;
    
    for ( int i = 0; i < n; i++ )
        if ( a[i] != b[i] )
            c.push_back(i);
        
    if ( c.size() == 0 ){
        std::cout << "yes";
    }
    else if ( c.size() == 2 ){ 
        if ( a[c[0]] == b[c[1]] && a[c[1]] == b[c[0]] )
            std::cout << "yes" << std::endl << "swap " << c[0]+1 << " " << c[1]+1;
        else
            std::cout << "no";
    }
    else if ( c.size() > 2 ) {
        bool flag = true;
        for ( int i = 0; i < c.size() && flag; i++ ){
            if ( a[c[i]] != b[c[c.size()-i-1]] )
               flag = false;
        }
        if ( flag ){
            std::cout << "yes" << std::endl << "reverse " << c[0]+1 << " " << c[c.size()-1]+1;
        }
        else{
            std::cout << "no";
        }
    }
  
    return 0;
}
