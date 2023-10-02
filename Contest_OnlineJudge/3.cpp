#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define int long long int
#define endl "\n"
#define F first
#define S second
#define uni(x) x.erase(unique(all(x)), x.end())
#define deb(args...){string _s = #args;replace(_s.begin(), _s.end(), ',', ' ');stringstream _ss(_s);istream_iterator<string> _it(_ss);err(_it, args);}
#define all(v) v.begin(), v.end()
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define multi_ordered_set tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>
#define index_of(x) order_of_key(x)
#define value_index(x) find_by_order(x)
ll modpow(ll a, ll b,ll m) {ll res = 1; while (b) {if (b & 1) res = res * a % m; a = a * a % m; b >>= 1;} return res;}
using namespace std;
using namespace __gnu_pbds;
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v)
{
    os << '{';
    for (const auto &x : v)
        os << " " << x;
    return os << '}';
}
void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
    cerr << *it << " = " << a << endl;
    err(++it, args...);
}
int dx[]={0, 0, 1, -1, 1, 1, -1, -1};
int dy[]={1, -1, 0, 0, 1, -1, 1, -1};
const int N=2e5+5,M=1e9+7;
void solve(int tt){
    int n,k,i;
    cin>>n>>k;
    int val=n+n/2;
    int val1=100000*(n/2)+99999*(n/2);
    if(k<val || k>val1 || (k%2==0 && n%4 ) || (k%2 && n%4==0))
    {
        cout<<-1<<endl;
        return;
    }
    int ar[n+1];
    int av=k/n;
    int m=k%n;
    for(i=1;i<=n;i++)
    {
        ar[i]=av;
        if(i<=m)
        {
            ar[i]++;
        }
    }
    int cnt=0;
    for(i=1;i<=n;i++)
    {
        if(ar[i]%2==0)
        {
            cnt++;
        }
    }
    if(cnt>=(n/2))
    {
        val=cnt-(n/2); 
        val1=val; 
        for(i=1;i<=n;i++)
        {
            if(val==0)
            {
                break;
            }
            if(ar[i]%2==0)
            {
                ar[i]--;
                val--;
            }
        }
        for(i=1;i<=n;i++)
        {
            if(val1==0)
            {
                break;
            }
            if(ar[i]+2<=100000)
            {
                ar[i]+=2;
                val1-=2;
            }
        }
    }
    else
    {
        val=(n/2)-cnt; 
        val1=val; 
        for(i=1;i<=n;i++)
        {
            if(val==0)
            {
                break;
            }
            if(ar[i]%2)
            {
                ar[i]--;
                val--;
            }
        }
        for(i=1;i<=n;i++)
        {
            if(val1==0)
            {
                break;
            }
           if(ar[i]+2<=100000)
            {
                ar[i]+=2;
                val1-=2;
            }
        }
    }
    if(val1>0)
    {
        cout<<-1<<endl;
        return;
    }
    for(i=1;i<=n;i++)
    {
        cout<<ar[i]<<" ";
    }
    cout<<endl;
    
} 

int32_t main()
{
    #ifdef DEBUG
        //freopen("input.txt", "r", stdin);
        // freopen("output.txt","w", stdout);
    #else
        ios_base::sync_with_stdio(false);
        cin.tie(NULL); 
    #endif
    ll test_case = 1;
    cin>>test_case;
    for(int i = 1; i <= test_case; i++){
        solve(i);
    }
}