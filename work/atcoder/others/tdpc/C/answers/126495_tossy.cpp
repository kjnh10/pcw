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
  int k;
  cin>>k;
  int n = 1<<k;
  vector<int> r(n);
  rep(i,n) cin>>r[i];
  vector<vector<double>> win(n, vector<double>(n,0));
  // win[i][j] iがjに勝つ確率
  rep(i,n) rep(j,n) if(i!=j){
    win[i][j] = 1.0/(1.0+pow(10.0, (r[j]-r[i])/400.0));
  }

  vector<vector<double>> dp(n, vector<double>(k+1, 0));
  rep(i,n) dp[i][0] = 1;
  rep(i,k) rep(j,n){
    int mask1 = ~((1<<(i+1))-1);
    int mask2 = 1<<i;
    rep(jj,n) if( j!=jj && ((j&mask1)==(jj&mask1)) && (j&mask2)!=(jj&mask2)){
      dp[j][i+1] += dp[jj][i]*win[j][jj];
    }
    dp[j][i+1] *= dp[j][i];
  }

  rep(i,n) printf("%.7f\n", dp[i][k]);

  return 0;
}
