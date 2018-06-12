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

int a,b,r,c,d,e,f;
bool incircle(int x, int y){
  int dx = x-a;
  int dy = y-b;
  if(dx*dx+dy*dy<=r*r)return true;
  return false;
}

int main(){
  cin>>a>>b>>r>>c>>d>>e>>f;
  bool flag = true;
  if(incircle(c,d)&&incircle(c,f)&&incircle(e,d)&&incircle(e,f))flag=false;
  bool flag2 = true;
  if(c<=a-r && a+r<=e && d<=b-r && b+r<=f)flag2=false;
  cout<<(flag2?"YES":"NO")<<endl;
  cout<<(flag?"YES":"NO")<<endl;
  return 0;
}
