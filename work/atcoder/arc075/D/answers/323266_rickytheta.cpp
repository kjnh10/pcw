#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

typedef int _loop_int;
#define REP(i,n) for(_loop_int i=0;i<(_loop_int)(n);++i)
#define FOR(i,a,b) for(_loop_int i=(_loop_int)(a);i<(_loop_int)(b);++i)
#define FORR(i,a,b) for(_loop_int i=(_loop_int)(b)-1;i>=(_loop_int)(a);--i)

#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define DEBUG_VEC(v) cout<<#v<<":";REP(i,v.size())cout<<" "<<v[i];cout<<endl
#define ALL(a) (a).begin(),(a).end()

#define CHMIN(a,b) a=min((a),(b))
#define CHMAX(a,b) a=max((a),(b))

// mod
const ll MOD = 1000000007ll;
#define FIX(a) ((a)%MOD+MOD)%MOD

// floating
typedef double Real;
const Real EPS = 1e-11;
#define EQ0(x) (abs(x)<EPS)
#define EQ(a,b) (abs(a-b)<EPS)
typedef complex<Real> P;

ll n,a,b;
ll h[125252];

bool ok(ll x){
  ll c = a-b;
  ll cnt = 0;
  REP(i,n){
    ll t = h[i] - x*b;
    if(t > 0)cnt += (t+c-1)/c;
  }
  return cnt <= x;
}

int main(){
  scanf("%lld%lld%lld",&n,&a,&b);
  REP(i,n)scanf("%lld",h+i);
  ll low = 0, high = 1000002521;
  while(low+1 < high){
    ll x = (low+high)/2;
    if(ok(x))high = x;
    else low = x;
  }
  printf("%lld\n",high);
  return 0;
}
