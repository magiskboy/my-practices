#include <iostream>
#include <vector>

std::vector<int> merge(std::vector<int> a, std::vector<int> b) {
    int n = a.size() + b.size();
    std::vector<int> c(n, 0);
    int i = 0, j = 0;
    for ( int k = 0; k < n; ++k ) {
        if ( a[i] > b[j] ) c[k] = b[j++];
        else c[k] = a[i++];
    }

    return c;
}

std::vector<int> sort(std::vector<int> arr, int l, int h) {
    if ( l == h ) return arr;
    else {
        int mid = (l + h) / 2;
        std::vector<int> a, b, c;
        a = sort(arr, l, mid);
        b = sort(arr, mid+1, h);
        c = merge(a, b);
        return c;
    }
}


int main(){
    std::vector<int> a, b;
    a.push_back(1);
    a.push_back(3);
    a.push_back(2);
    a.push_back(-4);
    a.push_back(0);
    a.push_back(7);
    b = sort( a, 0, a.size()-1 );
	
    for (int i = 0; i < a.size(); ++i) std::cout << a[i] << " ";
    std::cout << std::endl;
    for (int i = 0; i < b.size(); ++i) std::cout << b[i] << " ";
    std::cout << std::endl;

	return 0;
}
