#include <bits/stdc++.h>
#include<vector>
using namespace std;

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
int frq[30];
void solve(int tt){
    string s,t;
    cin >> s;
    cin >> t;
    map<char, int> m1;
    map <char, int> m2;
    for(int i = 0; i < s.size(); i++){
        m1[s[i]]++;
    }
    for(int i = 0; i < t.size(); i++){
        m2[t[i]]++;
    }
    string  s1 = " ";
    for(auto it:m1){
        char ch = it.first;
        if(m1[ch] > m2[ch]){
            int x = it.second;
            int y = m2[ch];
            for(int i = y; i < x; i++){
               s1 += ch;
            }
        }
    }
    cout << s1 << en;
    for(int i = 0; i < s.size(); i++){
        if(s[i] != t[i]){
            swap(s1[0], s1[i]);
            break;
        }
    }
   // cout << s1 << t << en;

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