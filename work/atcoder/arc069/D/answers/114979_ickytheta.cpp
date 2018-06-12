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
char s[125252];
int ans[125252];
const int SHEEP = 0, WOLF = 1;

bool valid(){
  REP(i,n){
    int a = i;
    int b = (i+1)%n;
    int c = (i+2)%n;
    int ox = (int)(s[b]!='o');
    if(ans[b]==WOLF)ox^=1;
    if(ans[a]^ox!=ans[c])return false;
  }
  return true;
}

int main(){
  scanf("%d",&n);
  scanf("%s",s);
  REP(a,2)REP(b,2){
    ans[0] = a;
    ans[1] = b;
    FOR(i,2,n){
      int ox = (int)(s[i-1]!='o');
      if(ans[i-1]==WOLF)ox^=1;
      ans[i] = ans[i-2]^ox;
    }
    if(valid()){
      REP(i,n)putchar(ans[i]==SHEEP?'S':'W');
      return 0;
    }
  }
  puts("-1");
  return 0;
}
