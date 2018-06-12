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
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n,x;
  cin>>n>>x;
  a.resize(n+2);
  forn(i,n)
    cin>>a[i+1];
  in sm=0;
  for(in i=1;i<=n;++i){
    if(a[i]+a[i-1]>x){
      sm+=a[i]+a[i-1]-x;
      a[i]=x-a[i-1];
    }
  }
  cout<<sm<<endl;
  return 0;
}
