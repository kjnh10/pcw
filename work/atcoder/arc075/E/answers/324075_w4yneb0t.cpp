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
struct fenw{
  VI fw;
  in n;
  void ini(in pn){
    n=pn;
    fw.clear();
    fw.resize(n,0);
  }
  void ad(in l, in x){
    while(l<n){
      fw[l]+=x;
      l|=(l+1);
    }
  }
  in sm(in l){
    in r=0;
    while(l>=0){
      r+=fw[l];
      l&=(l+1);
      --l;
    }
    return r;
  }
};
fenw fw;
in n;
vector<pair<in,in> > psm;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in k;
  cin>>n>>k;
  in ssf=0;
  psm.PB(MP(0,0));
  in a;
  forn(z,n){
    cin>>a;
    a-=k;
    ssf+=a;
    psm.PB(MP(ssf,z+1));
  }
  sort(all(psm));
  fw.ini(n+9);
  in sm=0;
  forv(i,psm){
    sm+=fw.sm(psm[i].second);
    fw.ad(psm[i].second,1);
  }
  cout<<sm<<endl;
  return 0;
}
