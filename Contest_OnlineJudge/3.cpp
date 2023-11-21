#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define Faster ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

#ifdef TESLA
#include "main.hpp"
#else
#define dbg(...)
#endif

int main(){
   Faster;
   int t;                  cin>>t;
   while(t--){
      int n;               cin>>n;
      vector<ll> a(n);
      for(int i=0;i<n;i++){
         cin>>a[i];
      }

      map<ll,int> freq;
      for(int i=0;i<n;i++){
         freq[a[i]]++;
      }
      
      ll ans=0,cons=0;
      sort(a.begin(),a.end());
      for(int i=0;i<n;i++){
         cons++;
         if(i==n-1 or a[i+1]!=a[i]){
            dbg(a[i], cons);
            ans+=((cons*(cons-1LL))/2LL);
            cons=0;
         }
         for(ll j=1;;j++){
            ll rhs=a[i]*(1LL<<j);
            dbg(a[i], rhs, j, freq[rhs], ans);
            if(rhs>a[n-1])break;
            if(!freq[rhs])continue;
            if(rhs-a[i]==j){
               ans+=freq[rhs];
            }
         }
      }

      cout<<ans<<endl;
   }
   return 0; 
}
