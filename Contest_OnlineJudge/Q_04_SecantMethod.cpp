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
#define mp make_pair
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

#define f(x) x*x*x - 2*x - 5
void solve(int tt){
    double x0, x1, x2, f0, f1, f2, e = 0.00001;
    cin >> x0 >> x1;
    while(1){
        f0 = f(x0);
        f1 = f(x1);
        if(f0 == f1){
            cout << "Division by zero error!" << endl;
            return;
        }
        x2 = x1 - (f1*(x1-x0))/(f1-f0);
        f2 = f(x2);
        dbg(tt, x0, x1, x2, f0, f1, f2);
        if(abs(f2) < e) break;
        x0 = x1;
        x1 = x2;
        f0 = f1;
        f1 = f2;
        tt++;
    }
    cout << "Root is: " << x2 << endl;
}
int32_t main(){
    #ifndef DEBUG
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
    #endif
    int t = 1;
    //cin >> t;
    for(int i = 1; i <= t; i++){
        solve(i);
    }
    return 0;
}