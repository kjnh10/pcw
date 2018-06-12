#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<cassert>
#define PB push_back
#define MP make_pair
#define sz(v) (in((v).size()))
#define forn(i,n) for(in i=0;i<(n);++i)
#define forv(i,v) forn(i,sz(v))
#define fors(i,s) for(auto i=(s).begin();i!=(s).end();++i)
#define all(v) (v).begin(),(v).end()
using namespace std;
typedef long long in;
typedef vector<in> VI;
typedef vector<VI> VVI;
const in mdl=1000000007;
in p2(in a){
  return 1LL<<a;
}
in pw(in a, in b){
  in r=1;
  for(in i=40;i>=0;--i){
    r=r*r%mdl;
    if(b&p2(i))
      r=r*a%mdl;
  }
  return r;
}
in fr(in a){
  if(a%2==0)
    return a/2;
  return (a+1)/2;
}
VI dvs;
VI hv;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n,k;
  cin>>n>>k;
  in sm=0;
  for(in i=1;i*i<=n;++i){
    if(n%i)
      continue;
    dvs.PB(i);
    if(n/i!=i)
      dvs.PB(n/i);
  }
  sort(all(dvs));
  hv=VI(sz(dvs),0);
  forv(i,hv){
    hv[i]=pw(k,fr(dvs[i]));
    forn(j,i){
      if(dvs[i]%dvs[j]==0)
	hv[i]-=hv[j];
    }
    hv[i]%=mdl;
    if(dvs[i]%2)
      sm+=hv[i]*dvs[i];
    else
      sm+=hv[i]*(dvs[i]/2);
    sm%=mdl;
  }
  sm%=mdl;
  if(sm<0)
    sm+=mdl;
  cout<<sm<<endl;
  return 0;
}
