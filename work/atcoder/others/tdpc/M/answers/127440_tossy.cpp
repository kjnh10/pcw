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

#define MAT_N 16
long mat[MAT_N][MAT_N];

// a * b = dst O(N^3)
long tmp[MAT_N][MAT_N];
void mat_mul(long a[][MAT_N], long b[][MAT_N], long dst[][MAT_N]){
  fill(tmp[0], tmp[MAT_N], 0);
  rep(i,MAT_N) rep(k,MAT_N) if(a[i][k]!=0) rep(j,MAT_N){
    tmp[i][j] += a[i][k] * b[k][j] % MOD;
  }
  rep(i,MAT_N) rep(j,MAT_N) dst[i][j] = tmp[i][j] %MOD;
}

// a^n = dst O(M^3 log N)
long tmp_pow[MAT_N][MAT_N];
void mat_pow(long a[][MAT_N], long n, long dst[][MAT_N]){
  rep(i,MAT_N) rep(j,MAT_N) tmp_pow[i][j] = a[i][j];
  fill(dst[0], dst[MAT_N], 0);
  rep(i,MAT_N) dst[i][i]=1;
  while(n>0){
    if(n&1) mat_mul(tmp_pow, dst, dst);
    mat_mul(tmp_pow, tmp_pow, tmp_pow);
    n /= 2;
  }
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

  fill(mat[0], mat[16], 0);
  rep(i,r)rep(j,r)rep(mask,1<<r) (mat[i][j] += dp[mask][i][j])%=MOD;
  mat_pow(mat, h, mat);

  cout << mat[0][0] << endl;

  return 0;
}
