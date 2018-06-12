#include <bits/stdc++.h>
using namespace std;
typedef long long int lld;
typedef vector<lld> vi;
typedef pair<lld,lld> pi;
#define F first
#define S second
#define MOD 1000000007
#define PB push_back
#define MP make_pair
#define rep(i,a,b) for (lld i = a; i < b; i++)
lld a,c,r,j,l,x,y,m,b,n,s,f,q,i,z,p,k,d,t,u,e,g;string s1,s2,s3,s4;
vi v[10000001];
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin>>x>>y;p=0;
  rep(i,x,y+1)
  {
    s1=to_string(i);
    s2=s1;reverse(s1.begin(), s1.end());
    if(s1==s2)
      p++;
  }
  cout<<p;
}