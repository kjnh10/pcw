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
int l;
int x[125252];
int kth[125252][20];

int main(){
  scanf("%d",&n);
  REP(i,n)scanf("%d",x+i);
  scanf("%d",&l);
  // kth next
  REP(i,n+1)REP(k,20)kth[i][k]=n;
  FORR(i,0,n){
    // check next
    kth[i][0] = upper_bound(x,x+n,x[i]+l)-x-1;
    // doubling
    FOR(k,1,20)kth[i][k] = kth[kth[i][k-1]][k-1];
  }
  // query
  int q;
  scanf("%d",&q);
  REP(i,q){
    int a,b;
    scanf("%d%d",&a,&b);
    --a;--b;
    if(a>b)swap(a,b);
    int ans = 0;
    FORR(k,0,20){
      int nxt = kth[a][k];
      if(nxt<b){
        a=nxt;
        ans += 1<<k;
      }
    }
    while(a<b){
      a=kth[a][0];
      ans++;
    }
    printf("%d\n",ans);
  }
  return 0;
}
