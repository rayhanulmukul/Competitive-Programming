# include <bits/stdc++.h> 
# include <cmath> 
using namespace std; 
 
// # define ll long long 
// # define setbits(x) __builtin_popcountll(x) 
// # define mod 1000000007 

int main() {
  long long t; cin>>t;
  while(t--){   
    long long n,x,y; cin>>n>>x>>y;
    long long a = y/3;
    long long b = 0;
    if( a > x){
      a = x;
    }
    else{
    b = (x - a)/2;
    }
    if(b+a >= n){
      cout<<"YES"<<endl;
    }
    else{
      cout<<"NO"<<endl;
    }
  }
}