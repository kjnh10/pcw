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
VVI wy;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n,k;
  cin>>n>>k;
  wy.resize(k+1,VI(n+1,0));
  wy[0][n]=1;
  for(in i=1;i<=k;++i){
    for(in j=n-1;j>=0;--j){
      wy[i][j]=wy[i][j+1]+wy[i-1][j+1];
    }
    forn(j,n){
      if(n-j>=i)
	wy[i][j]+=wy[i-1][j];
      wy[i][j]%=mdl;
    }
    if(i<k){
      wy[i][0]=0;
    }
  }
  in rs=wy[k][0];
  if(k<n){
    forn(z,n-k-1){
      rs*=2;
      rs%=mdl;
    }
  }
  cout<<rs<<endl;
  return 0;
}
