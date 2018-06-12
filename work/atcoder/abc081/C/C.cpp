using namespace std;
#include <iostream>/*{{{*/
#include <bits/stdc++.h>
#define rep(i, x) for(int i = 0; i < (int)(x); i++)
#define REPS(i,x) for(int i = 1; i <= (int)(x); i++)
#define RREP(i,x) for(int i=((int)(x)-1);i>=0;i--)
#define RREPS(i,x) for(int i=((int)(x));i>0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define RFOR(i, m, n) for(int i = m;i >= n;i--)
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define FILL(x,y) memset(x,y,sizeof(x))
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define PB(a) push_back(a)
// dump macro{{{
// http://www.creativ.xyz/dump-cpp-652
#define DUMPOUT cerr // 変数ダンプ先。coutかcerr
 
#define DEBUG_ // 提出時はコメントアウト
#ifdef DEBUG_
#define DEB
#else
// DEB と打つとデバッグ時以外はコメントアウトになる
#define DEB /##/
#endif
 
// 変数ダンプ用マクロ。デバッグ時以外は消滅する
// 引数はいくつでもどんな型でも可（ストリーム出力演算子があればOK）
#define dump(...) DEB DUMPOUT<<"  "; \
DUMPOUT<<#__VA_ARGS__; \
DUMPOUT<<":=> "; \
dump_func(__VA_ARGS__); DUMPOUT<<"in ["<<__LINE__<<":"<<__FUNCTION__<<"]"<<endl;
 
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
    for (int i = 0; i<vec.size(); i++) {
        os << vec[i] << (i + 1 == vec.size() ? "" : ", ");
    }
    os << "}";
    return os;
}/*}}}*/
#define debug(x) cerr << __LINE__ << ": " << #x << " -> " << x << '\n'
#define INF 999999999
typedef long long ll;
typedef pair<int, int> pii;
int dy[]={0, 0, 1, -1, 0};
int dx[]={1, -1, 0, 0, 0};/*}}}*/


int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n, k;
  cin >> n >> k;
  vector<int> c(n, 0);
  rep(i,n){
    int tmp;cin>>tmp;
    c[tmp-1] += 1;
  }

  sort(ALL(c), greater<int>());
  dump(c);

  int res=0;
  FOR(i, k, n){
    if(c[i] >= 1){
      res += c[i];
      dump(i, k, n);
    }
    else{
      break;
    }
  }

  cout << res << endl;


  return 0;
}
