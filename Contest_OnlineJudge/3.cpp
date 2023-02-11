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
#define sz(x) (int(x.size()))
#define mem(a, b) memset(a, b, sizeof(a))
#define sor(x)  sort(x.begin(), x.end())

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
    char a[3][n];
    FOR(i, 3){
        FOR(j, n){
            cin >> a[i][j];
        }
    }
    int c = 0, ans = 0, ma = 0;
    for(int j = 0; j < n; j++){
        int ok = 0;
        //cout << j << gap;
        if(j+1 < n && ((a[0][j] == 'O' && a[0][j+1] == 'O' && a[1][j] == 'O' && a[1][j+1] == 'O') || (a[1][j] == 'O' && a[1][j+1] == 'O' && a[2][j] == 'O' && a[2][j+1] == 'O'))){
            c++;
            j++;
        }
    }
    ma = c;
    c = 0, ans = 0;
    for(int j = 0; j < n; j++){
        int ok = 0;
        //cout << j << gap;
        if(j+1 < n && ((a[0][j] == 'O' && a[0][j+1] == 'O' && a[1][j] == 'O' && a[1][j+1] == 'O') || (a[1][j] == 'O' && a[1][j+1] == 'O' && a[2][j] == 'O' && a[2][j+1] == 'O'))){
            c++;
            ok = 1;
            j++;
        }
       // cout << ok << gap << c <<  j+1 << en;
        if(ok == 0 && j+1 != n){
            ans += ceil(c/2.0);
           //cout << ans << en;
           c = 0;
            ok = 0;
        }
        //cout << ans << en;
    }
   //cout << c << gap;
   if(c > 0) ans += c;
    //cout << c << gap;
    //cout << ans << en;
   //cout << ans << en;
  cout << ans <<  ": "  <<  ma << gap;
   if(ans%2 == 0 && ma%2 == 0){
       cout << "Case " << tt << ": " << "Grandma" << en;
   }
   else{
       cout << "Case " << tt << ": " << "Jhinuk" << en;
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