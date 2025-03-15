#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, e;
    std::vector<int> vi, vp;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cin >> e;
        vi.push_back(e);
        if (e > -1) {
            vp.push_back(i);
        } 
    }

    for (int i = 0; i < vp.size()-1; ++i) {
        for (int j = i + 1; j < vp.size(); ++j) {
            if (vi[vp[i]] > vi[vp[j]]) {
                std::swap(vi[vp[i]], vi[vp[j]]);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        std::cout << vi[i] << " ";    
    }

    return 0;
}
