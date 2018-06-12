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
VI wys[2];
const in mdl=1000000007LL;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n;
  cin>>n;
  string s;
  cin>>s;
  in k=sz(s);
  in sw=1;
  in nw=0;
  forn(z,2)
    wys[z].resize(n+3);
  wys[nw][0]=1;
  forn(i,n){
    swap(sw,nw);
    forv(p,wys[nw])
      wys[nw][p]=0;
    forn(p,n+1){
      if(p)
	wys[nw][p-1]+=wys[sw][p];
      else
	wys[nw][p]+=wys[sw][p];
      wys[nw][p+1]+=2*wys[sw][p];
    }
    if(i%5==0 || i==n-1){
      forv(p,wys[nw])
	wys[nw][p]%=mdl;
    }
  }
  in inv2=(mdl+1)/2;
  in rs=wys[nw][k];
  forn(i,k)
    rs=rs*inv2%mdl;
  cout<<rs<<endl;
  return 0;
}
