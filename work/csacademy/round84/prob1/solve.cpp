using namespace std;
#include <iostream>
#include <bits/stdc++.h>

#define infile "./test/sample-1.in"
#define int long long
// #define INF 2147483647
#define INFLL 1000000000000000000LL
#define MOD 1000000007LL
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
//{{{ dump macro
#define DUMPOUT cerr // where to dump. cout or cerr

#ifdef PCM
  #include "dump.hpp"
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
//}}}
//{{{ others
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
//}}}


int solve(){
  dump("hello");
  int n,w;cin>>n>>w;
  int a[n], b[n];
  rep(i, n){ cin>>a[i]>>b[i]; }
  int res = n;
  rep(i, n){
    if (a[i]==0) continue;
    int s = 0;
    FOR(j, i, n){
      if (a[j]==0) break;
      if (a[j]==1) s+=b[j];
      dump(i, j, s,w);
      if (s>=w) {
        chmin(res, i);
      }
    }
  }

  if (res==n){
    cout << -1 << endl;
  }
  else{
    cout << res+1 << endl;
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
