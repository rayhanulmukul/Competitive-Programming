#include <iostream>
#include <vector>
#include <climits>

using namespace std;
#define int long long

typedef pair<int, int> pii;
typedef vector<pii> vpii;

int ans(int cur, string &s, vpii &tree) {
    if (cur == -1) {
        return INT_MAX;
    }

    if (tree[cur] == make_pair(-1ll, -1ll)) {
        return 0;
    }

    int l = ans(tree[cur].first, s, tree);
    int r = ans(tree[cur].second, s, tree);

    if (s[cur] == 'L') {
        return min(l, r + 1);
    } else if (s[cur] == 'R') {
        return min(r, l + 1);
    } else {
        return min(l, r) + 1;
    }
}

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    vpii tree(n);

    for (int i = 0; i < n; ++i) {
        cin >> tree[i].first >> tree[i].second;
        tree[i].first--;
        tree[i].second--;
    }

    cout << ans(0, s, tree) << endl;
}

int32_t main() {
    int t;
    cin >> t;
    while(t--){
    solve();
    }
    return 0;
}
//c