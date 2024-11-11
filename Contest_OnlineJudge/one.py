void solve(int tc)
{
  int n,p;
  string s;
  cin>>n>>p;
  if(n==1 and p==1)s="Evenious";
  else if(n==1 and p==2)s="Oddius";
  else if(n%2==0 and p==2)s="Oddius";
  else if(n%2==0 and p!=2)s="Evenious";
  else if(n%2!=0 and p==2)s="Oddius";
  else if(n%2!=0 and p!=2)s="Oddius";
  cout<<"Case "<<tc<<": "<<s<<endl;
}