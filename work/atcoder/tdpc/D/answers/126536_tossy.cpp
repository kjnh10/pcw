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

double dp[2][64][40][30];

double solve(){
  int n;long d;
  cin>>n>>d;

  if(d==1) return 1.0;
  int t=0,s=0,u=0;
  while(d%2==0){s++; d/=2;}
  while(d%3==0){t++; d/=3;}
  while(d%5==0){u++; d/=5;}

  if(d!=1) return 0;

  // dp[i][s][t] 2がs個，3がt個，5がu個となる確率
  auto prev = dp[0];
  auto nxt = dp[1];
  fill(prev[0][0], prev[64][0], 0);
  prev[0][0][0]=1;
  rep(i,n){
    fill(nxt[0][0], nxt[64][0], 0);
    rep(j,s+1)rep(k,t+1)rep(l,u+1) if(prev[j][k][l]>0){
      double p = prev[j][k][l]/6.0;
      nxt[j][k][l] += p; // 1
      nxt[min(j+1,s)][k][l] += p; // 2
      nxt[j][min(k+1,t)][l] += p; // 3
      nxt[min(j+2,s)][k][l] += p; // 4
      nxt[j][k][min(l+1,u)] += p; // 5
      nxt[min(j+1,s)][min(k+1,t)][l] += p; // 6
    }
    swap(nxt, prev);
  }
  return prev[s][t][u];
}

int main(){
  printf("%.7f\n", solve());

  return 0;
}
