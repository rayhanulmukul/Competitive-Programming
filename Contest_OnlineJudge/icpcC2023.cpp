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
    int n;
    cin >> n;
    int a, b;
    cin >> a >> b;
    vector <int> v(n+1);
    for(int i = 1; i <= n; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int ans = 0;
    v[0] = -1e5;
    dbg(v);
    for(int i = 1; i <= n; i++){
        int x = v[i];
        int left = i+1, right = n;
        int low = n+1;
        while(left <= right){
            int mid = (left + right) / 2;
            if(b >= x + v[mid]){
                low = mid;
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        //dbg(x, i, low);
        int high = n+1;
        left = i+1, right = n;
        while(left <= right){
            int mid = (left + right) / 2;
            if(a <= x + v[mid]){
                high = mid;
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        dbg(low, high);
        if(low==n+1 || high==n+1) continue;
        ans += low - high+1;
    }
    cout << "Case " << tt << ": " << ans << endl;
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