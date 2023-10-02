#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
#include <bits/stdc++.h>
#include<vector>
using namespace std;
using namespace __gnu_pbds;

#define ll long long int
#define int ll
#define ld long double
#define pb push_back
#define ft front()
#define bk back()
#define pi 2*acos(0.0)     /// acos(-1) , 3.14159265359
#define gap ' '
#define en '\n'
#define endl en
#define sz(x) (int)(x.size())
#define mem(a, b) memset(a, b, sizeof(a))
#define sor(x)  sort(x.begin(), x.end())

#ifdef TESLA
#include "main.hpp"
#else
#define dbg(...)
#endif
//dbug(), watch(), output_run_time()
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rng(x,y) uniform_int_distribution<int>(x,y)(rng)
#define F0R(i,a,b) for (int i = (a); i < (b); ++i)
#define FOR(i,a) F0R(i,0,a)
#define R0F(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define ROF(i,a) R0F(i,0,a)
#define each(a,x) for (auto& a: x)
const int MOD = 1e9+7; // 998244353;
const int MAX = 2e5+5;
const int N = 1005;

void solve(int tt){
    int n, m, k;
    cin >> n >> m >> k;
    vector <int> a(n), b(m);
    vector <int> c, d;
    int ans = 0, mna = 2e18, mxa = -2e18, mnb = 2e18, mxb = -2e18;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        ans += a[i];
        mna = min(mna, a[i]);
        mxa = max(mxa, a[i]);
    } 
    c.push_back(mna), c.push_back(mxa);
    for(int i = 0; i < m; i++){
        cin >> b[i];
        mnb = min(mnb, b[i]);  
        mxb = max(mxb, b[i]);
    }
    d.push_back(mnb), d.push_back(mxb);
    sort(c.begin(), c.end());
    sort(d.begin(), d.end());
    if(k%2 == 1){
        int x = c[0];
        c[0] = max(c[0], d[1]);
        dbg(x, c);
        cout << ans - x + c[0] << endl;
    }
    else{
        vector <int> temp = c;
        int x, x0;
        x = c[0];
        dbg("main", c, d);
        c[0] = max(c[0], d[1]);
        d[1] = min(d[1], x);
        dbg("Odd : ", c, d);
        sort(c.begin(), c.end());
        sort(d.begin(), d.end());
        x = c[1];
        x0 = d[0];
        d[0] = max(d[0], c[1]);
        c[1] = min(c[1], x0);
        dbg("Even", ans, c, d);

        int ans1 = 0, ans2 = 0;
        for(int i = 0; i < 2; i++){
            ans1 += c[i];
        }
        for(int i = 0; i < 2; i++){
            ans2 += temp[i];
        }
        cout << ans - ans2 + ans1 << endl;
    }
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