/* template.cpp [[[ */
#include <bits/stdc++.h>
using namespace std;
#define get_macro(a, b, c, d, name, ...) name
#define rep(...) get_macro(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)
#define rrep(...) get_macro(__VA_ARGS__, rrep4, rrep3, rrep2, rrep1)(__VA_ARGS__)
#define rep1(n) rep2(i_, n)
#define rep2(i, n) rep3(i, 0, n)
#define rep3(i, a, b) rep4(i, a, b, 1)
#define rep4(i, a, b, s) for (ll i = (a); i < (ll)(b); i += (ll)s)
#define rrep1(n) rrep2(i_, n)
#define rrep2(i, n) rrep3(i, 0, n)
#define rrep3(i, a, b) rrep4(i, a, b, 1)
#define rrep4(i, a, b, s) for (ll i = (ll)(b) - 1; i >= (ll)(a); i -= (ll)s)
#define each(x, c) for (auto &&x : c)
#define fs first
#define sc second
#define all(c) begin(c), end(c)
using ll = long long;
using ld = long double;
const int INF = 1e9 + 10;
const ll INF_LL = 1e18 + 10;
const int dx[]{-1, 0, 1, 0, -1, 1, 1, -1};
const int dy[]{0, -1, 0, 1, -1, -1, 1, 1};
template<class T, class U> void chmin(T &x, const U &y){
  x = min<T>(x, y);
}
template<class T, class U> void chmax(T &x, const U &y){
  x = max<T>(x, y);
}
template<class C> size_t lbound(const C &c, const typename C::value_type &x){
  return lower_bound(all(c), x) - begin(c);
}
template<class C> size_t ubound(const C &c, const typename C::value_type &x){
  return upper_bound(all(c), x) - begin(c);
}
string to_lower(string s){
  transform(begin(s), end(s), begin(s), ::tolower);
  return s;
}
string to_upper(string s){
  transform(begin(s), end(s), begin(s), ::toupper);
  return s;
}
/* ]]] */

int main(){
  string s;
  cin >> s;
  cout << (s.back() == 'T' ? "YES\n" : "NO\n");
}
