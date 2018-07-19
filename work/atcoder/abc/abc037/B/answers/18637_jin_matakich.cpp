/* template.cpp {{{ */
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
#define mp make_pair
#define mt make_tuple
#define eb emplace_back
#define pb pop_back
#define ef emplace_front
#define pf pop_front
#define all(c) begin(c), end(c)
#define uniq(c) sort(all(c)), (c).erase(unique(all(c)), end(c))
#define csize(c) ((ll)((c).size()))
#define lbnd(c, x) (lower_bound(all(c), (x)) - begin(c))
#define ubnd(c, x) (upper_bound(all(c), (x)) - begin(c))
using ll = long long;
using uint = unsigned;
using ull = unsigned long long;
using ld = long double;
const int INF = 1e9 + 10;
const ll INF_LL = 1e18 + 10;
template<class T, class... U> void chmin(T &x, U... y){ x = min<T>(x, T(y...)); }
template<class T, class... U> void chmax(T &x, U... y){ x = max<T>(x, T(y...)); }
/* }}} */

int n, q, l, r, t;
int a[100];

int main(){
  cin >> n >> q;
  rep(q){
    cin >> l >> r >> t;
    rep(i, l - 1, r) a[i] = t;
  }
  rep(i, n) cout << a[i] << endl;
}

