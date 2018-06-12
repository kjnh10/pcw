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

int n;
int a[125252];

// -val, minx
set<pii> S;

ll ans[125252];

int main(){
  scanf("%d",&n);
  REP(i,n)scanf("%d",a+i);
  REP(i,n)S.insert(pii(-a[i],i));
  REP(i,n-1){
    auto it = S.begin();
    pii A = *(it++);
    pii B = *it;
    ll sz = i+1;
    ll av = -A.first;
    ll bv = -B.first;
    ll nxtv = bv;
    int id = A.second;
    int nxtid = min(A.second, B.second);
    ll sa = av-bv;
    ans[id] += sa*sz;
    S.erase(S.begin());
    S.erase(S.begin());
    S.insert(pii(-nxtv,nxtid));
  }
  ll rest = -(S.begin()->first);
  ans[0] += rest * n;
  REP(i,n)printf("%lld\n",ans[i]);
  return 0;
}
