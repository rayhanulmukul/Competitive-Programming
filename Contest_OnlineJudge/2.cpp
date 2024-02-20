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
    string s;
    getline(cin, s);
    if(s.size() == 0){
        getline(cin, s);
    }
    int n = s.size();
    dbg(s);
    string day = s.substr(0, 2);
    string month = s.substr(3, 2);
    string year = s.substr(6, 4);
    string weekDay = s.substr(11, 3);
    dbg(day, month, year, weekDay);
    int d = stoi(day);
    cout << "|---------------------------|" << endl;
    cout << "|Sun|Mon|Tue|Wed|Thu|Fri|Sat|" << endl;
    cout << "|---------------------------|" << endl;
    cout << "|";
    int cnt = 0;
    if(weekDay == "Sun"){
        cnt = 0;
    }else if(weekDay == "Mon"){
        cnt = 1;
    }else if(weekDay == "Tue"){
        cnt = 2;
    }
    else if(weekDay == "Wed"){
        cnt = 3;
    }
    else if(weekDay == "Thu"){
        cnt = 4;
    }
    else if(weekDay == "Fri"){
        cnt = 5;
    }
    else if(weekDay == "Sat"){
        cnt = 6;
    }

    int mon1 = 31, mon2 = 28, mon3 = 31, mon4 = 30, mon5 = 31, mon6 = 30, mon7 = 31, mon8 = 31, mon9 = 30, mon10 = 31, mon11 = 30, mon12 = 31;
    if(month == "02"){
        if((stoi(year) % 4 == 0 && stoi(year) % 100 != 0) || (stoi(year) % 400 == 0)){
            mon2 = 29;
        }
    }
    int mon = stoi(month);
    int year1 = stoi(year);
    if(mon == 2){
        int x = d - (d / 7) * 7;
        cnt = abs(cnt - x);
        dbg(x, cnt);
        int cnt1 = 0;
        for(int i = 1; i <= cnt; i++){
            cout << " - |";
            cnt1++;
        }
        int i;
        int week = 1;
        for(i = 1; i <= mon2; i++){
            if(cnt1 == 7){
                week++;
                if(week == 6) break;
                cout << endl;
                cout << "|---------------------------|" << endl;
                cout << "|";
                cnt1 = 0;
            }
            if(i < 10){
                cout << "  " << i << "|";
            }else{
                cout << " " << i << "|";
            }
            cnt1++;
        }
        for(int j = mon2 + 1; j <= 35; j++){
            if(cnt1 == 7){
                week++;
                if(week == 6) break;
                cout << endl;
                cout << "|---------------------------|" << endl;
                cout << "|";
                cnt1 = 0; 
            }
            cout << " - |";
            cnt1++;
        }
        cout << en;
        cout << "|---------------------------|" << endl;
        dbg(i);
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