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
    string s;
    cin >> s;
    map <char, int> mp;
    for(auto x : s){
        mp[x]++;
    }
    //"blue", "green", "yellow", "red", "purple", "orange", "pink", "grey", "cyan", "brown", "ash", "silver", "gold", "white", "black" 
    vector <string> str;
    str.pb("blue"), str.pb("green"), str.pb("yellow"), str.pb("red"), str.pb("purple"), str.pb("orange"), str.pb("pink"), str.pb("grey"), str.pb("cyan"), str.pb("brown"), str.pb("ash"), str.pb("silver"), str.pb("gold"), str.pb("white"), str.pb("black");
    int ans = 0;
    for(int i = 0; i < sz(str); i++){
        string x = str[i];
        int cnt = 0;
        for(auto y : x){
            if(mp[y] > 0){
                cnt++;
            }
        }
        if(cnt == sz(x)){
            ans++;
            for(auto y : x){
                mp[y]--;
            }
        }
    }                
    cout << ans << en;
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