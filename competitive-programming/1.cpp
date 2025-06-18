/*بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيمِ*/
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
#include <bits/stdc++.h>
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
#include "dbg.h"
#else
#define dbg(...)
#endif
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define rng(x,y) uniform_int_distribution<int>(x,y)(rng)
#define F0R(i,a,b) for (int i = (a); i < (b); ++i)
#define FOR(i,a) F0R(i,0,a)
const int MOD = 1e9+7;
const int MAX = 2e5+5;
const int INF = 1e18;
int dx[] = {0, 0, +1, -1, -1, +1, -1, +1};
int dy[] = {+1, -1, 0, 0, +1, +1, -1, -1};

void solve(int tt){
    int n, m;
    cin >> n >> m;
    vector <vector<int>> a(n, vector<int>(m));

    int col = 0, row = 0;
    int mx_val = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
            if(a[i][j] > mx_val){
                mx_val = a[i][j];
            }
        }
    }

    vector <int> row_cal, col_cal;

    for(int i = 0; i < n; i++){
        int cnt = 0;
        for(int j = 0; j < m; j++){
            if(a[i][j] == mx_val){
                cnt++;
            }
        }
        row_cal.pb(cnt);
    }
    for(int j = 0; j < m; j++){
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(a[i][j] == mx_val){
                cnt++;
            }
        }
        col_cal.pb(cnt);
    }

    dbg(row, col, row_cal, col_cal, row_mx, col_mx);

    int col_mx1 = 0;
    for(int i = 0; i < col_cal.size(); i++){
        if(col_cal[i] > col_mx1){
            col_mx1 = col_cal[i];
            col = i;
        }
    }

    int row_mx1 = 0;
    for(int i = 0; i < row_cal.size(); i++){
        if(row_cal[i] > row_mx1){
            row_mx1 = row_cal[i];
            row = i;
        }
    }

    if(n == 1 or m == 1){
        for(int i = 0; i < n; i++){
            a[i][col]--;
        }
        int val = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(a[i][j] > val){
                    val = a[i][j];
                }
            }
            if(val > mx_val){
                mx_val = val;
            }
        }
        cout << mx_val << endl;
        return;
    }


    if(row_mx1 <= col_mx1){
        for(int i = 0; i < n; i++){
            a[i][col]--;
        }

        // dbg(a);

        if(m > 1 && n > 1){
            vector <int> row_cal1; 
            for(int i = 0; i < n; i++){
                int cnt = 0;
                for(int j = 0; j < m; j++){
                    if(a[i][j] == row_mx){
                        cnt++;
                    }
                }
                row_cal1.pb(cnt);
            }
            
            int row_mx2 = 0;
            for(int i = 0; i < row_cal1.size(); i++){
                if(row_cal[i] > row_mx2){
                    row_mx2 = row_cal1[i];
                    row = i;
                }
            }

            for(int i = 0; i < m; i++){
                a[row][i]--;
            }
        }

        // dbg(a);

        int val = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(a[i][j] > val){
                    val = a[i][j];
                }
            }
        }
        cout << val << endl;
    }
    else{
        for(int j = 0; j < m; j++){
            a[row][j]--;
        }

        if(n > 1){
            vector <int> col_cal1;
            for(int j = 0; j < m; j++){
                int cnt = 0;
                for(int i = 0; i < n; i++){
                    if(a[i][j] == col_mx){
                        cnt++;
                    }
                }
                col_cal1.pb(cnt);
            }

            int col_mx2 = 0;
            for(int i = 0; i < col_cal1.size(); i++){
                if(col_cal1[i] > col_mx2){
                    col_mx2 = col_cal1[i];
                    col = i;
                }
            }

            for(int j = 0; j < n; j++){
                a[j][col]--;
            }
        }
        int val = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(a[i][j] > val){
                    val = a[i][j];
                }
            }
        }
        cout << val << endl;
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