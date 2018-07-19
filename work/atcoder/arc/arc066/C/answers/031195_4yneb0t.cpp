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
in ab(in a){
  return a<0?-a:a;
}
map<in,in> shd,hv;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n;
  cin>>n;
  forn(i,n)
    ++shd[ab(i-(n-i-1))];
  in a;
  forn(i,n){
    cin>>a;
    ++hv[a];
  }
  if(hv!=shd){
    cout<<0<<endl;
    return 0;
  }
  const in mdl=1000000007;
  in sm=1;
  fors(i,shd)
    if(i->second==2)
      sm=sm*2%mdl;
  cout<<sm<<endl;
  return 0;
}
