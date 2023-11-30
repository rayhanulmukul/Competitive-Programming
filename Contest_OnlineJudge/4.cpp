#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> array(n);
        for (int i = 0; i < n; ++i) {
            cin >> array[i];
        }

        int sum_remaining = 0;
        vector<pair<int, int>> dp(n + 1, {0, 1});

        for (int i = n - 1; i >= 0; --i) {
            auto [total, count] = dp[i + 1];
            dp[i] = {total + array[i], count};
            dp[i] = max(dp[i], make_pair(total + sum_remaining + array[i], count + 1));
            sum_remaining += array[i];
        }

        cout << dp[0].first << endl;
    }

    return 0;
}
