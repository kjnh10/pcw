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
#define long long long // for codeforces

int main(){
  int n;
  cin>>n;
  vector<vector<int>> vec(n,vector<int>(n));
  rep(i,n) rep(j,n) cin>>vec[i][j];

  vector<vector<int>> dp(n, vector<int>(n, -INF));
  dp[0][0] = 0;

  repl(i,1,n){
    int mx = -INF;
    int acc = 0;
    rep(j,i) acc += vec[i][j];
    rep(j,i){
      mx = max(mx, dp[i-1][j]);
      dp[i][j] = mx + acc;
      acc -= vec[i][j];
    }
    dp[i][i] = mx;
  }

  int res = -INF;
  rep(i,n) res = max(res, dp[n-1][i]);
  cout << res*2 << endl;

  return 0;
}
