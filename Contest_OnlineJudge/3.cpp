#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MOD = 1000000007;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }

    sort(a.begin(), a.end());

    int m = 1;
    for (int i = 1; i < n; i++) {
        if (a[i].first == a[0].first) {
            m++;
        } else {
            break;
        }
    }

    vector<long long> f(m+1);
    f[1] = 1;
    for (int i = 2; i <= m; i++) {
        long long p = 0;
        for (int j = 1; j < i; j++) {
            if (a[j-1].first < a[i-1].first) {
                p = (p + f[j]) % MOD;
            }
        }
        f[i] = p * 1LL * (n-i+2) % MOD * (n-i+1) % MOD;
    }

    long long ans = 0;
    for (int i = 1; i <= m; i++) {
        ans = (ans + f[i]) % MOD;
    }
    cout << ans << endl;

    return 0;
}
