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

int n,m;
int a[125252];
ll imo[252521];
ll imo2[252521];

int main(){
  scanf("%d%d",&n,&m);
  REP(i,n)scanf("%d",a+i),a[i]--;
  REP(i,n-1){
    int from = a[i];
    int to = a[i+1];
    if(to < from)to += m;
    imo[from+1]++;
    imo[to+1]--;
    imo2[to+1]-=(to-from);
  }
  REP(i,2*m+1)imo[i+1]+=imo[i];
  REP(i,2*m+1)imo2[i]+=imo[i];
  REP(i,2*m+1)imo2[i+1]+=imo2[i];
  REP(i,m)imo2[i]+=imo2[i+m];
  int x = max_element(imo2,imo2+m)-imo2;
  ll ans = 0;
  REP(i,n-1){
    int from = a[i];
    int to = a[i+1];
    if(to < from)to += m;
    int y = x;
    if(y < from)y += m;
    if(from < y && y <= to){
      ans++;
      from = y;
    }
    ans += to-from;
  }
  printf("%lld\n",ans);
  return 0;
}
