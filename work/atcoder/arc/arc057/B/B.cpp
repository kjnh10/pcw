using namespace std;
#include <iostream>
#include <bits/stdc++.h>

#define infile "./test/sample-1.in"
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
// n次元配列の初期化。第２引数の型のサイズごとに初期化していく。
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}
#define fill(x,y) memset(x,y,sizeof(x))
#define pb(a) push_back(a)
#define uni(x) sort(all(x));x.erase(unique(all(x)),x.end())
#define ten(n) ((int)1e##n)
#define INF 2147483647
#define INFLL 1000000000000000000LL
#define MOD 1000000007
// }}}

// dump macro{{{
// http://www.creativ.xyz/dump-cpp-652
#define DUMPOUT cerr // 変数ダンプ先。coutかcerr

#ifdef PCM
// 引数はいくつでもどんな型でも可（ストリーム出力演算子があればOK）
#define dump(...) DUMPOUT<<"  "; \
  DUMPOUT<<#__VA_ARGS__; \
  DUMPOUT<<":=> "; \
  dump_func(__VA_ARGS__); DUMPOUT<<"in ["<<__LINE__<<":"<<__FUNCTION__<<"]"<<endl;
#define dump_1d(x,n) DUMPOUT <<"  " \
  <<#x<<"["<<#n<<"]"<<":=> {"; \
  rep(i,n){ DUMPOUT << x[i] << (((i)==(n-1))?"}":", "); } DUMPOUT <<" in [" << __LINE__ << "]" << endl;

#define dump_2d(x,n,m) DUMPOUT <<"  " \
    <<#x<<"["<<#n<<"]"<<"["<<#m<<"]"<<":=> \n"; \
    rep(i,n)rep(j,m){ DUMPOUT << ((j==0)?"     |":" ") << x[i][j] << (((j)==(m-1))?"|\n":" "); } \
    DUMPOUT <<"  in [" << __LINE__ << "]" << endl;
#else
#define dump(...) 42
#define dump_1d(...) 42
#define dump_2d(...) 42
#endif

// デバッグ用変数ダンプ関数
void dump_func() {
}
template <class Head, class... Tail>
void dump_func(Head&& head, Tail&&... tail)
{
    DUMPOUT << head;
    if (sizeof...(Tail) == 0) {
        DUMPOUT << " ";
    }
    else {
        DUMPOUT << ", ";
    }
    dump_func(std::move(tail)...);
}

// vector出力
template<typename T>
ostream& operator << (ostream& os, vector<T>& vec) {
    os << "{";
    for (int i = 0; i<sz(vec); i++) {
        os << vec[i] << (i + 1 == sz(vec) ? "" : ", ");
    }
    os << "}";
    return os;
}/*}}}*/

struct Fast {  //{{{
  Fast(){
    std::cin.tie(0);
    ios::sync_with_stdio(false);
  }
} fast;
typedef long long ll;
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
int dx[]={1, -1, 0, 0, 0};

// }}}

ll dp[2001][2001];
int solve(){
  ll n, k;cin>>n>>k;
  if (k==0){
    cout << 0 << endl;
    return 0;
  }

  ll a[n], s[n+1]; s[0]=0;
  rep(i, n){ cin>>a[i]; s[i+1] = s[i]+a[i]; }
  dump_1d(s, n+1);

  rep(i, 2001) rep(j, 2001) dp[i][j]=INF;
  dp[0][0]=0;

  FOR(i, 0, n) rep(j, i+1){
    //dp[i][j]からの遷移
    if (dp[i][j]==INF) continue;
    ll d = k-(s[n]-s[i+1]); //勝利数の下限
    ll w; //機嫌が上がる勝利数
      if (i==0){ w=1; }
      else if(dp[i][j]==s[i]){ w=INF; }
      else{ w=(dp[i][j]*s[i+1])/s[i] + 1; }

    ll u = min(dp[i][j]+s[i+1], k); //可能な勝利数の上限
    if (d>u) continue;
    if (d<w)  { dp[i+1][j] =   min(dp[i+1][j], max(dp[i][j], d)); }
    if (w<=u) { dp[i+1][j+1] = min(dp[i+1][j+1], max(w,d)); }
  }

  dump_2d(dp, n+1, n+1);

  ll res = 1;
  reps(i, n){
    if (dp[n][i]==k){
      res = i;
    }
  }
  cout << res << endl;

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
