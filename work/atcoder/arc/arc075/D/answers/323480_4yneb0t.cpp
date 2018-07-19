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
in n,a,b;
VI h;
bool isk(in c){
  in nd=0;
  forn(i,n){
    nd+=(max(h[i]-c*b,0LL)+a-1)/a;
  }
  return nd<=c;
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>a>>b;
  a-=b;
  h.resize(n);
  forn(i,n)
    cin>>h[i];
  in mn=0;
  in mx=1e9+10;
  in md;
  while(mx-mn>1){
    md=(mx+mn)/2;
    if(isk(md))
      mx=md;
    else
      mn=md;
  }
  cout<<mx<<endl;
  return 0;
}
