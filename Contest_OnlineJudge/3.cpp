#include <bits/stdc++.h>
using namespace std;

int main() {
   vector<int> v = {1, 2, 3, 4, 5};
    int x = 3;

    // Search for element x in vector v
    auto it = find(v.begin(), v.end(), x);

    if (it != v.end()) {
        std::cout << "Element " << x << " found at position "
                  << distance(v.begin(), it) << std::endl;
    } else {
        std::cout << "Element not found" << std::endl;
    }

    return 0;
}
