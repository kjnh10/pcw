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
/*
[l,r]
if l!=r
in [l+1,r] increment by x-(l+1)
 */
VI ntx;
VI nta;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n,m;
  cin>>m>>n;
  ntx.resize(n+1);
  nta.resize(n+1);
  in pv=-1;
  in a;
  in ttl=0;
  forn(z,m){
    cin>>a;
    --a;
    if(pv==-1 || pv==a){
      pv=a;
      continue;
    }
    ttl+=(a-pv);
    if(a<pv)
      ttl+=n;
    if(pv<a){
      ntx[pv+1]+=1;
      nta[pv+1]-=pv+1;
      ntx[a+1]-=1;
      nta[a+1]+=pv+1;
    }
    else{
      ntx[pv+1]+=1;
      nta[pv+1]-=pv+1;
      ntx[n]-=1;
      nta[n]+=pv+1;
      ntx[0]+=1;
      nta[0]-=pv+1;
      nta[0]+=n;
      ntx[a+1]-=1;
      nta[a+1]+=pv+1;
      nta[a+1]-=n;
    }
    pv=a;
  }
  in mx=-1e18;
  in crx=0;
  in cra=0;
  forn(i,n){
    crx+=ntx[i];
    cra+=nta[i];
    mx=max(mx,crx*i+cra);
  }
  cout<<ttl-mx<<endl;
  return 0;
}
