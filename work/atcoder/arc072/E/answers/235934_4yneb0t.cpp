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
VI d;
VI sml;
VI ed;
in td;
in n;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>td;
  d.resize(n);
  sml.resize(n+1);
  ed.resize(n+1);
  forn(i,n)
    cin>>d[i];
  sml[n]=1;
  for(in i=n-1;i>=0;--i){
    if(d[i]>=sml[i+1]*2){
      sml[i]=sml[i+1];
    }
    else{
      sml[i]=sml[i+1]+d[i];
    }
  }
  ed[0]=td;
  forn(i,n){
    if(d[i]>=ed[i]*2){
      ed[i+1]=ed[i];
    }
    else{
      if(d[i]<=ed[i]){
	ed[i+1]=ed[i]-d[i];
      }
      else{
	ed[i+1]=d[i]-ed[i];
      }
    }
  }
  in Q;
  cin>>Q;
  in q;
  forn(zz,Q){
    cin>>q;
    --q;
    if(ed[n]!=0){
      cout<<"YES\n";
    }
    else{
      if(sml[q+1]<=ed[q])
	cout<<"YES\n";
      else
	cout<<"NO\n";
    }
  }
  return 0;
}
