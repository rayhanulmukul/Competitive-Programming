#include<bits/stdc++.h>
#include <stdlib.h>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define f0(i,n) for(int i=0;i<=n;i++)
#define first_IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define in_buffer cin.ignore(numeric_limits<streamsize>::max(), '\n')
#define ordered_set tree<ll, null_type, less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update>
#define ll long long
#define int long long
#define zero (long long)0
#define double long double
#define pb push_back
#define pii make_pair
#define goto_hell return 0
#define newline cout  << "\n"
#define endl "\n" // << flush
#define all(x) x.begin(),x.end()
#define sz(x) x.size()
#define one (long long)1
using namespace __gnu_pbds;
using namespace std;
char gap = 32;
template<typename T> 
ostream& operator<<(ostream &os, const vector<T> &v) { 
    os << '{'; 
    for (const auto &x : v) os << gap << x;
        return os << '}'; 
}
template<typename A, typename B> 
ostream& operator<<(ostream &os, const pair<A, B> &p) {
        return os << '(' << p.first << gap << p.second << ')';
}
const int mod = 1e9+7;
const int inf = 1e17;

int bipow(int a,int b)
{
    int res = 1;
    while(b>zero)
    {
        if(b&one)
        {
            res*=a;
            res%=mod;
        }
        b = b >> one;
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
        mp.clear();
        build(s,mid);
        // if(mid==5) {
        //     cout << mp[{2986408,3885340}] << endl;
        // }
        if(chck(s,mid)) {
            res = mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    cout << res << endl;
}

int32_t main() {
    first_IO;
    int test=1;
    //cin >> test;
    //cout << "Test = " << test << endl;
    //in_buffer;
    for(int t=1;t<=test;t++)solve(t);
    goto_hell;
}