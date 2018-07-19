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

// #define MOD (ll)(1e9+7)
#define ADD(a,b) a=((a)+(b))%MOD
#define FIX(a) ((a)%MOD+MOD)%MOD


int n,k;
int a[125252];
ll sma[125252];

int main(){
  scanf("%d%d",&n,&k);
  REP(i,n)scanf("%d",a+i);
  ll sum = 0;
  REP(i,n)sma[i+1]=a[i];
  REP(i,n)sma[i+1] += sma[i];
  REP(i,n-k+1)sum += sma[i+k]-sma[i];
  cout<<sum<<endl;
  return 0;
}
