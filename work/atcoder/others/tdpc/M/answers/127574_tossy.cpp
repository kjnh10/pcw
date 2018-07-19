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

typedef vector<vector<long>> mat;

// return A*B
mat mat_mul(const mat &A, const mat &B){
  int n=A.size(), m=B[0].size(), l=B.size();
  mat ret(n, vector<long>(m, 0));
  rep(i,n) rep(k,l) if(A[i][k]!=0) rep(j,m){
    (ret[i][j] += A[i][k] * B[k][j]) %= MOD;
  }
  return ret;
}

// A^p
mat mat_pow(const mat &A, long p){
  int n = A.size();
  mat tmp(A), ret(n, vector<long>(n,0));
  rep(i,n) ret[i][i] = 1;
  while(p>0){
    if(p&1) ret = mat_mul(tmp, ret);
    tmp = mat_mul(tmp, tmp);
    p /= 2;
  }
  return ret;
}

long dp[1<<16][16][16];

int main(){
  int h,r;
  cin>>h>>r;
  vector<vector<int>> vec(r,vector<int>(r));
  rep(i,r) rep(j,r) cin>>vec[i][j];

  fill(dp[0][0], dp[1<<16][0], 0);
  // [mask][s][t] maskを通ってsからtにいく
  rep(i,r) dp[1<<i][i][i] = 1;
  rep(mask, 1<<r) rep(i,r) rep(j,r) if(dp[mask][i][j]>0){
    rep(k,r) if((mask&(1<<k))==0 && vec[j][k]==1){
      (dp[mask | (1<<k)][i][k] += dp[mask][i][j])%=MOD;
    }
  }

  mat m(r, vector<long>(r,0));
  rep(i,r) rep(j,r) rep(mask,1<<r) (m[i][j] += dp[mask][i][j])%=MOD;
  m = mat_pow(m, h);

  cout << m[0][0] << endl;

  return 0;
}
