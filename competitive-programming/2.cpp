#include <iostream>
<<<<<<< Updated upstream
using namespace std;

void solve(int tt) {
    int x;
    cin >> x;

    // Try y as the largest power of 2 less than x
    int y = 1;
    while (y * 2 < x) {
        y *= 2;
    }

    // Check y and y-1 as candidates
    for (int candidate : {y, y - 1}) {
        if (candidate >= 1 && candidate < x) {
            int z = x ^ candidate;
            if (x + candidate > z && candidate + z > x && x + z > candidate) {
                cout << candidate << endl;
                return;
            }
        }
    }

    // If no valid y is found, output -1
    cout << -1 << endl;
}

int main() {
    int tt;
    cin >> tt;
    while (tt--) {
        solve(tt);
=======
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (auto &x : a) cin >> x;

        vector<long long> suffix(n + 2, 0);
        for (int i = n-1; i >= 0; --i) {
            suffix[i] = suffix[i+1] + a[i];
        }

        vector<long long> pref_max(n, 0);
        pref_max[0] = a[0];
        for (int i = 1; i < n; ++i) {
            pref_max[i] = max(pref_max[i-1], a[i]);
        }

        for (int k = 1; k <= n; ++k) {
            long long ans = suffix[n - k];

            if (n - k - 1 >= 0) {
                ans = max(ans, suffix[n - k + 1] + pref_max[n - k - 1]);
            }

            cout << ans << " ";
        }
        cout << '\n';
>>>>>>> Stashed changes
    }
}
