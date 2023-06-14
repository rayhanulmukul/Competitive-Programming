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


int call(string s){
    int maxm = -1, ans = 0;
    int n = s.size();
    for(int i = n-1; i >= 0; i--){
        if(s[i] == 'A'){
            if(maxm <= 1){
                ans += 1;
                maxm = 1;
            }
            else ans -= 1;
        }
        else if(s[i] == 'B'){
            if(maxm <= 10){
                ans += 10;
                maxm = 10;
            }
            else ans -= 10;
        }
        else if(s[i] == 'C'){
            if(maxm <= 100){
                ans += 100;
                maxm = 100;
            }
            else ans -= 100;
        }
        else if(s[i] == 'D'){
            if(maxm <= 1000){
                ans += 1000;
                maxm = 1000;
            }
            else ans -= 1000;
        }
        else if(s[i] == 'E'){
            if(maxm <= 10000){
                ans += 10000;
                maxm = 10000;
            }
            else ans -= 10000;
        }
    }
    return ans;
}
void solve(int tt){
    int maxans = 0;
    string s; cin >> s;
    int n = s.size();
    maxans = call(s);
    for(char ch = 'A'; ch <= 'E'; ch++){
        int flag = -1;
        for(int i = 0; i < n; i++){
            if(s[i] == ch){
                flag = i;
                break;
            }
        }
        if(flag != -1){
            string s1 = s;
            for(char cha = ch+1; cha <= 'E'; cha++){
                s1[flag] = cha;
                maxans = max(maxans, call(s1));
            }
            dbg(s1);
        }
    }
    for(char ch = 'A'; ch <= 'E'; ch++){
        int flag = -1;
        for(int i = n-1; i >= 0; i--){
            if(s[i] == ch){
                flag = i;
                break;
            }
        }
        if(flag != -1){
            for(char cha = ch-1; cha >= 'A'; cha--){
                string s1 = s;
                s1[flag] = cha;
                maxans = max(maxans, call(s1));
            }
        }
    }
   cout << maxans << en;
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