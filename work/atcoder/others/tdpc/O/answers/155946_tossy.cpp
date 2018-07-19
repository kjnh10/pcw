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

long comb[300][300];
void init_comb(){
  fill(comb[0],comb[300],0);
  comb[0][0] = 1;
  repl(i,1,300){
    comb[i][0] = 1;
    rep(j,i) comb[i][j+1] = (comb[i-1][j]+comb[i-1][j+1])%MOD;
  }
}

int main(){
  init_comb();
  vector<long> f(26);
  rep(i,26) cin>>f[i];

  vector<long> x;
  rep(i,26) if(f[i]>0) x.pb(f[i]);
  vector<long> acc(x.size()+1, 0);
  rep(i,x.size()) acc[i+1] = acc[i] + x[i];

  vector<vector<long>> dp(x.size()+1, vector<long>(250,0));

  dp[0][0] = 1;
  rep(i, x.size()) rep(j,200) if(dp[i][j]>0){
    // acc[i]:いまの状態までの総文字数
    // x[i]:  新たに追加する文字の個数
    // j:     いまの状態での連続文字箇所
    // k:     新たに追加する文字を何分割するか
    // l:     kのうち，jをいくつ消費するか
    repl(k,1,x[i]+1) rep(l,min(k,j)+1){
      if(acc[i]+1-j < k-l) continue;
      long c1 = comb[x[i]-1][k-1];
      long c2 = comb[j][l];
      long c3 = comb[acc[i]+1-j][k-l];
      dp[i+1][j-l+x[i]-k] += (dp[i][j]*c1)%MOD * (c2*c3%MOD) %MOD;
      dp[i+1][j-l+x[i]-k] %= MOD;
    }
  }

  cout << dp[x.size()][0] << endl;

  return 0;
}
