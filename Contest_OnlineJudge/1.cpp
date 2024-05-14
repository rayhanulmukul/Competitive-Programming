#include <bits/stdc++.h>

using namespace std;
#ifdef TESLA
#include "main.hpp"
#else
#define dbg(...)
#endif

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) {
        cin >> x;
    }
    map<int, vector<int>> mp;
    for (int i = 0; i < n; i++) {
        mp[a[i] >> 2].push_back(i);
    }
    for (auto &[x, y] : mp) {
        auto z = y;
        sort(z.begin(), z.end(), [&](const int &i, const int &j) {
            return a[i] < a[j];
        });
        for (int j = 0; j < z.size(); j++) {
            z[j] = a[z[j]];
        }
        for (int j = 0; j < z.size(); j++) {
            a[y[j]] = z[j];
        }
    }
    for (int i = 0; i < n; i++) {
        cout << a[i] << " \n"[i == n - 1];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
