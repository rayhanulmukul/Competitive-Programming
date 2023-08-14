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

const int mod = 1e9+7;
const int inf = 1e17;

int bipow(int a,int b)
{
    int res = 1;
    while(b)
    {
        if(b&1)
        {
            res*=a;
            res%=mod;
        }
        b = b >> 1;
        a*=a;
        a%=mod;
    }
    return res;
}

map<pair<int,int>,int>mp;

void build(string &s,int len) {
    int p1=1;int p2=1;
    int n=s.size();
    int rv1 = bipow(29,mod-2);
    int rv2 = bipow(31,mod-2);
    pair<int,int>hash;
    hash.first=0;
    hash.second=0;
    for(int i=0;i<len;i++) {
        if(i>0) {
            p1*=29;p1%=mod;
            p2*=31;p2%=mod;
        }
        int num = s[i]-'a';
        hash.first+=p1*num;hash.first%=mod;
        hash.second+=p2*num;hash.second%=mod;
    }
    mp[hash]=0;
    dbg(mp, hash, s, len);
    for(int i=len;i<n;i++) {
        int num = s[i-len]-'a';
        hash.first-=num;if(hash.first<0)hash.first+=mod;
        hash.first*=rv1;hash.first%=mod;
        hash.second-=num;if(hash.second<0)hash.second+=mod;
        hash.second*=rv2;hash.second%=mod;
        num=s[i]-'a';
        //if(i==2)cout << num << endl;
        hash.first+=num*p1;hash.first%=mod;
        hash.second+=num*p2;hash.second%=mod;
        mp[hash]=i-len+1;
    }
}

bool chck(string &s,int len) {
    int p1=1;int p2=1;
    int n=s.size();
    int rv1 = bipow(29,mod-2);
    int rv2 = bipow(31,mod-2);
    pair<int,int>hash;
    hash.first=0;
    hash.second=0;
    for(int i=0;i<len;i++) {
        if(i>0) {
            p1*=29;p1%=mod;
            p2*=31;p2%=mod;
        }
        int num = s[i]-'a';
        hash.first+=p1*num;hash.first%=mod;
        hash.second+=p2*num;hash.second%=mod;
    }
    //dbg(mp, hash, s, len);
    if(mp[hash]>=len)return true;
    for(int i=len;i<n;i++) {
        int num = s[i-len]-'a';
        hash.first-=num;if(hash.first<0)hash.first+=mod;
        hash.first*=rv1;hash.first%=mod;
        hash.second-=num;if(hash.second<0)hash.second+=mod;
        hash.second*=rv2;hash.second%=mod;
        num=s[i]-'a';
        hash.first+=num*p1;hash.first%=mod;
        hash.second+=num*p2;hash.second%=mod;
        if(mp[hash]>i)return true;
    }
    return false;
}

void solve(int test) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int l=0;int r=(s.size()/2);
    int res = 0;
    while(l<=r) {
        int mid = (l+r)/2;
        dbg(l, r, mid, res);
        mp.clear();
        build(s,mid);
        if(chck(s,mid)) {
            dbg(mid);
            res = mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    cout << res << endl;
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