#include <iostream>
#include <vector>

using namespace std;

#define en '\n'

void solve(int tt) {
    int n;
    cin >> n;
    vector<int> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    
    vector<int> increasing, decreasing;
    increasing.push_back(s[0]);

    for (int i = 1; i < n; i++) {
        if (s[i] > increasing.back()) {
            increasing.push_back(s[i]);
        } else {
            while (!increasing.empty() && s[i] < increasing.back()) {
                decreasing.push_back(increasing.back());
                increasing.pop_back();
            }
            increasing.push_back(s[i]);
        }
    }

    int ans = decreasing.size();
    cout << ans << en;
}

int main() {
    int tt = 1;
     cin >> tt;
    for (int i = 1; i <= tt; i++) {
        solve(i);
    }
    return 0;
}
