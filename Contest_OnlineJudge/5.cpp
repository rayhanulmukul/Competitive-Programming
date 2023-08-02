#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<queue>
#include<stack>
#include<unordered_map>
#include <math.h>
#include <climits>
#include <list>
#include <map>
#include <set>
#include <utility>
#define ll long long
#define mod 10000007
using namespace std;
 
#define int int64_t
#define vi vector<int>
#define vii vector<pair<int, int>>
#define vs vector<string>
#define vc vector<char>
#define vb vector<bool>
#define pb push_back
#define vvi vector<vector<int>>
#define pii pair<int, int>
#define umapii unordered_map<int,int>
#define umapci unordered_map<char,int>
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define loop(i, j, k) for (int i = j; i < k; i += 1)
#define rloop(i, j, k) for (int i = j; i >= k; i -= 1)
#define endl "\n"
#define inf (int)1e18
#define minf -9223372036854775807
#define PI 3.1415926535897932384626433832795
class customio{
    public:
    void operator>>(vi &arr){
        for (auto &x: arr) 
        cin >> x;
        return;
    }
    void operator<<(vi &arr){
        for (auto x: arr) 
        cout <<x<< " ";
    }
}vio;
#define cp(t) \
    int t;    \
    cin >> t; \
    while (t--)
 
// int gcd(int a, int b)
//{
//      if (b == 0)
//           return a;
//      return gcd(b, a % b);
// }
 
// int lcm(int a, int b) { return a * b / gcd(a, b); }
 
// void primeFactors(int n)
// {
//     while (n % 2 == 0)
//     {
//         cout << 2 << " ";
//         n = n/2;
//     }
//     for (int i = 3; i <= sqrt(n); i = i + 2)
//     {
//         while (n % i == 0)
//         {
//             cout << i << " ";
//             n = n/i;
//         }
        
//     }
//     if (n > 2)
//         {
//             cout << n << " ";
//         }
// }
 
// all indices which have value 0 will be prime number
// ll GA[10000001];
// void prime()
//{
//      memset(GA, 0, 10000001);
//      GA[0] = GA[1] = 1;
//      for (ll i = 2; i < 10000001; i++)
//      {
//           if (GA[i] == 0)
//           {
//                for (ll j = i * i; j < 10000001; j = j + i)
//                     GA[j] = 1;
//           }
//      }
// }
 
//ll power(ll x, ll y, ll p)
//{
//    int res = 1;
//   while (y > 0) {
//       if (y % 2 == 1)
//            res = ((res%p) * (x%p))%p;
//        y = y >> 1;
//        x = ((x%p) * (x%p))%p;
//    }
//    return res % p;
//}
 
 
// ll modexp(ll x, ll n)
// {
//     if (n == 0) {
//         return 1;
//     }
//     else if (n % 2 == 0) {
//         return modexp((x * x) % mod, n / 2);
//     }
//     else {
//         return (x * modexp((x * x) % mod, (n - 1) / 2) % mod);
//     }
// }
// ll getFractionModulo(ll a, ll b)
// {
//     ll c = gcd(a, b);
 
//     a = a / c;
//     b = b / c;
//     ll d = modexp(b, mod - 2);
//     ll ans = ((a % mod) * (d % mod)) % mod;
 
//     return ans;
// }


#ifdef TESLA
#include "main.hpp"
#else
#define dbg(...)
#endif


signed main(){
    ios_base::sync_with_stdio(false);
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    srand(time(NULL));
 
    cp(t){
        int n,m;
        cin>>n>>m;
        string s;
        cin>>s;
        vi nz(n),no(n);
        int nzero=-1,none=n+1;
        for(int i=0;i<n;i++){
            if(s[i]=='0') nzero=i;
            nz[i]=nzero;
        }
        for(int i=n-1;i>=0;i--){
            if(s[i]=='1') none=i;
            no[i]=none;
        }
        dbg(nz,no);
        
    }
}