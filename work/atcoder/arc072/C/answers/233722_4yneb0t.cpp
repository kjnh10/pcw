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
VI a;
in sol(){
  in sm=0;
  in sf=0;
  forv(i,a){
    sf+=a[i];
    if(i%2==0){
      if(sf<0)
	continue;
      sm+=(sf+1);
      sf=-1;
    }
    else{
      if(sf>0)
	continue;
      sm+=(1-sf);
      sf=1;
    }
  }
  return sm;
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n;
  cin>>n;
  a.resize(n);
  forn(i,n)
    cin>>a[i];
  in r=sol();
  forn(i,n)
    a[i]=-a[i];
  r=min(r,sol());
  cout<<r<<endl;
  return 0;
}
