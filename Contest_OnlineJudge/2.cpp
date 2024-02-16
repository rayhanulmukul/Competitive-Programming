#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
#include <bits/stdc++.h>
using namespace std;
using namespace __gnu_pbds;

#define ll long long int
#define int ll
#define ld long double
#define pb push_back
#define ft front()
#define bk back()
#define pi 2*acos(0.0)
#define gap ' '
#define en '\n'
#define endl en
#define mem(a, b) memset(a, b, sizeof(a))
#ifdef TESLA
#include "main.hpp"
#else
#define dbg(...)
#endif
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rng(x,y) uniform_int_distribution<int>(x,y)(rng)
#define F0R(i,a,b) for (int i = (a); i < (b); ++i)
#define FOR(i,a) F0R(i,0,a)
const int MOD = 1e9+7; // 998244353;
const int MAX = 2e5+5;
const int N = 1005;
const int INF = 1e18;
int dx[] = {0, 0, +1, -1, -1, +1, -1, +1};
int dy[] = {+1, -1, 0, 0, +1, +1, -1, -1};

void solve(int tt){
    int n;
    cin >> n;
    vector <int> a(n), b(n);
    map <int, int> mp;
    FOR(i, n){
        cin >> a[i];
        mp[a[i]]++;
    }
    b = a;
    sort(b.begin(), b.end());
    int cnt = 0;   
    int x, y;
    FOR(i, n){
        if(a[i] != b[i]){
            x = a[i];
            y = b[i];
            cnt++;
        }
    }
    dbg(cnt, x, y);
    if(cnt <= 2){
        int ind1 = -1, ind2 = -1;
        bool ok = 0;
        for(int i = 0; i < n; i++){
            if(a[i] == x and !ok){
                ind1 = i;
                ok = 1; 
            }
            else if(a[i] == y){
                ind2 = i;
            }
        }
        dbg(ind1, ind2);
        if((ind1 + 1 == ind2 || ind2 + 1 == ind1) && ind1 != -1 && ind2 != -1){
            if(mp[x] > 1 or mp[y] > 1){
                cout << "YES" << en;
            }
            else cout << "NO" << en;
        }
        else cout << "YES" << en;
    }
    else cout << "NO" << en;

}
int32_t main(){
#ifndef DEBUG
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#endif
    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++){
        solve(i);
    }
    return 0;
}