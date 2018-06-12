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
vector<string> gd={"dream","dreamer","erase","eraser"};
VI cr;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin>>s;
  in n=sz(s);
  cr.resize(n+1,0);
  cr[0]=1;
  forn(i,n){
    if(!cr[i])
      continue;
    forv(j,gd){
      if(sz(gd[j])+i<=n){
	if(s.substr(i,sz(gd[j]))==gd[j])
	  cr[i+sz(gd[j])]=1;
      }
    }
  }
  if(cr[n])
    cout<<"YES"<<endl;
  else
    cout<<"NO"<<endl;
  return 0;
}
