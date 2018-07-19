#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cassert>
#include<cstring>
#include<climits>
#include<sstream>
#include<deque>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<bitset>

#define REP(i,s,n) for(int i=s;i<n;++i)
#define rep(i,n) REP(i,0,n)

using namespace std;

typedef long long ll;

#define MAX 300000

long long mod = 1000000007;


long long extgcd(long long a,long long b,long long& x,long long& y)
{
  long long d = a;
  if(b != 0){
    d = extgcd(b,a%b,y,x);
    y -= (a/b)*x;
  }
  else
    x = 1,y = 0;
  return d;
}

long long mod_inv(long long a,long long m)
{
  long long x,y;
  extgcd(a,m,x,y);
  return (m+x%m)%m;
}

int n,k;
long long frac[MAX], denom[MAX];

long long f(ll x) {
  if( x == 1 ) return 1;
  return ( ( frac[x+k-1] * mod_inv(frac[x-1],mod) ) % mod * mod_inv(frac[k],mod) ) % mod;
}

int main() {
  frac[0] = frac[1] = 1;
  REP(i,2,MAX) frac[i] = ( frac[i-1] * (ll)i ) % mod;
  cin >> n >> k;
  cout << f(n) << endl;
  return 0;
}
