using namespace std;
#include <iostream>
#include <bits/stdc++.h>

#define ten(n) ((int)1e##n)
#define uni(x) sort(all(x));x.erase(unique(all(x)),x.end())
// n次元配列の初期化。第２引数の型のサイズごとに初期化していく。
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

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
    for (int i = 0; i<(int)vec.size(); i++) {
        os << vec[i] << (i + 1 == (int)vec.size() ? "" : ", ");
    }
    os << "}";
    return os;
}/*}}}*/

#define rep(i, x) for(int i = 0; i < (int)(x); i++)/*{{{*/
#define reps(i,x) for(int i = 1; i <= (int)(x); i++)
#define rrep(i,x) for(int i=((int)(x)-1);i>=0;i--)
#define rreps(i,x) for(int i=((int)(x));i>0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define RFOR(i, m, n) for(int i = m;i >= n;i--)
#define foreach(x,a) for(auto& (x) : (a) )
#define all(x) (x).begin(),(x).end()
#define sum(v) accumulate(all(v), 0)
#define sz(x) ((int)(x).size())
#define fill(x,y) memset(x,y,sizeof(x))
#define pb(a) push_back(a)
#define INF 2147483647
#define INFLL 1000000000000000000LL
#define MOD 1000000007/*}}}*/

struct Fast {Fast(){std::cin.tie(0);ios::sync_with_stdio(false);}} fast;/*{{{*/
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

/*}}}*/

//--------------------------------------------------------------------------

int main() {
  ll n,a;cin>>n>>a;
  vector<ll> x(n), y(n);
  map<int, vi> z;
  map<int, vi> v;
  rep(i, n){
    cin>>x[i]>>y[i];
    z[x[i]].pb(y[i]);
    v[y[i]].pb(x[i]);
  }
  uni(x); uni(y);

  for (auto p: z){ sort(all(z[p.first])); }
  for (auto p: v){ sort(all(v[p.first])); }

  ll l, pl;
  ll S = 0;
  rep(i, a/x[x.size()-1] + 1){
    S += v[i].size();
  }
  ll res = S;

  rrep(i, x.size()){
    if (i==0) break;
    pl = a/x[i];
    l = a/x[i-1];

    //  横の追加
    FOR(j, pl+1, min(l, 1000000ll)+1){
      if (sz(v[j])){
        S+=upper_bound(all(v[j]), x[i-1]) - v[j].begin();
      }
    }

    //  縦の削除
    S-=upper_bound(all(z[x[i]]), pl) - z[x[i]].begin();

    res = max(res, S);
  }

  cout << res << endl;

  return 0;
}
