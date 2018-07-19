using namespace std;
#include <iostream>
#include <bits/stdc++.h>

#define infile "./test/sample-1.in"
#define int long long
// {{{ define basic macro
#define rep(i, x) for(int i = 0; i < (int)(x); i++)
#define reps(i,x) for(int i = 1; i <= (int)(x); i++)
#define rrep(i,x) for(int i=((int)(x)-1);i>=0;i--)
#define rreps(i,x) for(int i=((int)(x));i>0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define RFOR(i, m, n) for(int i = m;i >= n;i--)
#define foreach(x,a) for(auto& (x) : (a) )
#define all(x) (x).begin(),(x).end()
#define sum(v) accumulate(all(v), 0)
#define sz(x) ((int)(x).size())
template<class T> inline void chmax(T &a, const T &b) { if(a < b) a = b; }
template<class T> inline void chmin(T &a, const T &b) { if(a > b) a = b; }
// n次元配列の初期化。第２引数の型のサイズごとに初期化していく。
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}
#define fill(x,y) memset(x,y,sizeof(x))
#define pb(a) push_back(a)
#define uni(x) sort(all(x));x.erase(unique(all(x)),x.end())
#define ten(n) ((int)1e##n)

template <class T = int>
T in() {T x; cin>>x; return (x);}

struct Fast {
  Fast(){
    std::cin.tie(0);
    ios::sync_with_stdio(false);
  }
} fast;
// }}}

typedef long long ll;/*{{{*/
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<long long> vll;
typedef vector<vll> vvll;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<pii> vii;
typedef vector<vii> vvii;
typedef tuple<int,int,int> iii;
typedef set<int> si;
typedef complex<double> pnt;
typedef vector<pnt> vpnt;
typedef priority_queue<pii,vii,greater<pii> > spq;
int dy[]={0, 0, 1, -1, 0};
int dx[]={1, -1, 0, 0, 0};/*}}}*/
#define INF 2147483647
#define INFLL 1000000000000000000LL
#define MOD 1000000007

#include "dump.hpp"

int dp[31][31][31][31];

int solve(){
  vi x={3,5,6,6};
  dump(x);
  int n,m;cin>>n>>m;
  vvi t;
  rep(i, n){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    t.push_back({a,b,c,d});
  }

  rep(i, 31) rep(j, 31) rep(k, 31) rep(l, 31){
    dp[i][j][k][l] = INF;
  }

  dp[0][0][0][0] = 0;

  rep(i, 31) rep(j, 31) rep(k, 31) rep(l, 31){
    rep(idx, n){
      int p,q,r,s;
      p = min(i+t[idx][0], 30LL);
      q = min(j+t[idx][1], 30LL);
      r = min(k+t[idx][2], 30LL);
      s = min(l+t[idx][3], 30LL);
      chmin(dp[p][q][r][s], dp[i][j][k][l] + 1);
    }
  }

  rep(i, m){
    int a,b,c,d;cin>>a>>b>>c>>d;
    int res = INF;
    rep(i, 31) rep(j, 31) rep(k, 31) rep(l, 31){
      if (i>=a && j>=b && k>=c && l>=d) chmin(res, dp[i][j][k][l]);
    }
    cout << res << endl;
  }

  return 0;
}

signed main() { //{{{
#ifdef INPUT_FROM_FILE
  std::ifstream in(infile);
  std::cin.rdbuf(in.rdbuf());
#endif
  solve();
  return 0;
} //}}}
