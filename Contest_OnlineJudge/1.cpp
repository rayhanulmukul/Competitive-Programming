#include<bits/stdc++.h>
using namespace std;
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
    int n;
    cin>>n;
    string s;
    cin>>s;
    map<char,int>mp;
    set<char>s1;
    for(int i=0;i<s.length();i++)
    {
      mp[s[i]]++;
      s1.insert(s[i]);
    }
     int p=s1.size();
     set<char>s2;
     int mx=0;
     int temp;
     for(int i=0;i<s.length();i++)
     {
      mp[s[i]]--;
      if(mp[s[i]]==0)
       p--;
      
      s2.insert(s[i]);
      
      temp=s2.size();
        mx=max(mx,(temp+p));
   
     }

     cout<<mx<<endl;
   }

}