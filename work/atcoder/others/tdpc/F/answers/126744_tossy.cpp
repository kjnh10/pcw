#include <bits/stdc++.h>
using namespace std;
#define repl(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define rep(i,n) repl(i,0,n)
#define mp(a,b) make_pair((a),(b))
#define pb(a) push_back((a))
#define all(x) (x).begin(),(x).end()
#define uniq(x) sort(all(x)),(x).erase(unique(all(x)),end(x))
#define fi first
#define se second
#define dbg(x) cout<<#x" = "<<((x))<<endl
template<class T,class U> ostream& operator<<(ostream& o, const pair<T,U> &p){o<<"("<<p.fi<<","<<p.se<<")";return o;}
template<class T> ostream& operator<<(ostream& o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}

#define INF 2147483600
#define MOD 1000000007

int main(){
  long k,n;
  cin>>n>>k;

  vector<long> dp(n+1, 0);
  vector<long> acc(n+1,0);
  dp[0] = 0;
  dp[1] = 1;
  dp[2] = 0;
  acc[0] = 0;
  acc[1] = 1;
  acc[2] = 1;
  repl(i,3,n+1){
    dp[i] = (acc[i-1] - acc[max<int>(i-k-1,0)] + MOD)%MOD;
    acc[i] = (acc[i-1] + dp[i])%MOD;
  }
  long res=0;
  for(int i=max<int>(n+1-k+1,0); i<n+1; i++) (res += dp[i])%=MOD;

  cout << res << endl;

  return 0;
}
