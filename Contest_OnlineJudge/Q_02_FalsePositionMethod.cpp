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

// F(x) = x^3 - 4x - 9
// False Position Method
int funct(double x){
    return (x * x * x) - 4 * x - 9;
}
void falsemethod(double a, double b){
    if(funct(a) * funct(b) >= 0){
        cout << "Invalid Interval" << en;
        return;
    }
    double c = a;
    int i = 1;
    while(i < 20){
        c = (a * funct(b) - b * funct(a)) / (funct(b) - funct(a));
        if(funct(c) == 0){
            break;
        }
        else if(funct(a) * funct(c) < 0){
            b = c;
        }
        else{
            a = c;
        }
        //dbg(i, c, funct(c), b, a);
        i++;
    }
    cout << "The value of root is : " << c << en;
}
void solve(int tt){
    double a, b;
    cin >> a >> b;
    falsemethod(a, b);
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