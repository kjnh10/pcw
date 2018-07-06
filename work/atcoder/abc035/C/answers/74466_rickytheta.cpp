#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef complex<double> P;
typedef pair<int,int> pii;
#define REP(i,n) for(ll i=0;i<n;++i)
#define REPR(i,n) for(ll i=1;i<n;++i)
#define FOR(i,a,b) for(ll i=a;i<b;++i)

#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define DEBUG_VEC(v) cout<<#v<<":";REP(i,v.size())cout<<" "<<v[i];cout<<endl
#define ALL(a) (a).begin(),(a).end()

#define MOD (ll)(1e9+7)
#define ADD(a,b) a=((a)+(b))%MOD
#define FIX(a) ((a)%MOD+MOD)%MOD

int po[252521];

int main(){
  int n,q;
  scanf("%d%d",&n,&q);
  REP(i,q){
    int l,r;
    scanf("%d%d",&l,&r);
    po[l-1] ^= 1;
    po[r] ^= 1;
  }
  REP(i,n){
    if(i!=0)po[i]^=po[i-1];
    printf("%d",po[i]);
  }
  printf("\n");
  return 0;
}
