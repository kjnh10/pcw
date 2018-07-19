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
in fu(in nu, in nn, in ou){
  if(nu<nn)
    return 0;
  if(nu>nn)
    return 2;
  return ou;
}
vector<VVI> wys,nwys;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n;
  cin>>n;
  ++n;
  in nn;
  wys.resize(3,VVI(2,VI(2)));
  wys[1][1][0]=1;
  forn(i,61){
    nn=!!(n&(1LL<<i));
    nwys=vector<VVI>(3,VVI(2,VI(2)));
    forn(ou,3){
      forn(cnc,2){
	forn(cc,2){
	  if(!cnc && !cc)
	    continue;
	  forn(nu,2){
	    forn(nx,2){
	      bool ncnc=0;
	      bool ncc=0;
	      forn(a,2){
		forn(b,2){
		  forn(actc,2){
		    if(actc==0 && !cnc)
		      continue;
		    if(actc==1 && !cc)
		      continue;
		    in au=a+b+actc;
		    in ax=a^b;
		    if(au%2!=nu || ax!=nx)
		      continue;
		    if(au/2)
		      ncc=1;
		    else
		      ncnc=1;
		  }
		}
	      }
	      if(ncnc || ncc)
		nwys[fu(nu,nn,ou)][ncnc][ncc]+=wys[ou][cnc][cc];
	    }
	  }
	}
      }
    }

    wys=nwys;
    forv(i,wys){
      forv(j,wys[i]){
	forv(k,wys[i][j])
	  wys[i][j][k]%=mdl;
      }
    }
  }
  in sm=0;
  sm+=wys[0][1][0];
  sm+=wys[0][1][1];
  sm%=mdl;
  cout<<sm<<endl;
  return 0;
}
