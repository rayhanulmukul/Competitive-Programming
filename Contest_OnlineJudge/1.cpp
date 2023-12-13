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
#define pi 2*acos(0.0)
#define gap ' '
#define en '\n'
#define endl en
#define mem(a, b) memset(a, b, sizeof(a))
#ifdef TESLA
#include "main.hpp"
#else
#define dbg(...)
#endif
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rng(x,y) uniform_int_distribution<int>(x,y)(rng)
#define F0R(i,a,b) for (int i = (a); i < (b); ++i)
#define FOR(i,a) F0R(i,0,a)
const int MOD = 1e9+7; // 998244353;
const int MAX = 2e5+5;
const int N = 1005;
const int INF = 1e18;
int dx[] = {0, 0, +1, -1, -1, +1, -1, +1};
int dy[] = {+1, -1, 0, 0, +1, +1, -1, -1};

void solve(int tt){
    int n, m;
    cin >> n >> m;
    vector <vector <int>> mat(n, vector <int> (m));
    FOR(i, n){
        FOR(j, m){
            cin >> mat[i][j];
        }
    }
    vector <int> rows(mat.size());
    vector <int> colums(mat[0].size());
    FOR(i, n){
        FOR(j, m){
            if(mat[i][j] == 1){
                dbg(i, j);
                rows[i]++;
                colums[j]++;
            }
        }
    }
    dbg(mat);
    dbg(rows, colums);
    int sum = 0;
    FOR(i, n){
        FOR(j, m){
            if(mat[i][j] == 1){
                if(rows[i] == 1 && colums[j] == 1){
                    sum++;
                }
            }
        }
    }
    cout << sum << en;
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