#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <deque>
#include <functional>
#include <iomanip>
#include <climits>
#include <locale>
#include <iostream>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(x) (x).begin(),(x).end()

using namespace std;

using ll = long long;
using ld = long double;

template <typename T> T &chmin(T &a, const T &b) { return a = min(a, b); }
template <typename T> T &chmax(T &a, const T &b) { return a = max(a, b); }
template <typename T> int len(const T &x) { return x.size(); }

template<typename T>
vector<T> table(int n, T v) { return vector<T>(n, v); }

template <class... Args>
auto table(int n, Args... args) {
  auto val = table(args...);
  return vector<decltype(val)>(n, move(val));
}

struct yes_no : numpunct<char> {
  string_type do_truename()  const { return "YES"; }
  string_type do_falsename() const { return "NO"; }
};

template <class Monoid>
class SegmentTree {
  using T = typename Monoid::type;
  const int sz, n;
  std::vector<T> data;
  int expand(int n) const { return n == 1 ? n : expand((n + 1) / 2) * 2; }
public:
  SegmentTree(const std::vector<T> &init) :
    sz(init.size()), n(expand(sz)), data(n * 2, Monoid::id()) {
    std::copy(begin(init), end(init), begin(data) + n);
    for (int i = n - 1; i >= 0; --i) {
      data[i] = Monoid::op(data[i * 2 + 0], data[i * 2 + 1]);
    }
  }
  SegmentTree(const int n, const T &init = Monoid::id()) :
    SegmentTree(std::vector<T>(n, init)) {}
  int size() const { return sz; }
  void update(int p, T val) {
    assert (0 <= p && p < sz); // assertion
    data[p += n] = val;
    while (p /= 2) data[p] = Monoid::op(data[p * 2], data[p * 2 + 1]);
  }
  T query(int l, int r) const {
    assert (0 <= l && l <= r && r <= sz); // assertion
    l += n; r += n;
    T res1 = Monoid::id(), res2 = Monoid::id();
    while (l != r) {
      if (l % 2) res1 = Monoid::op(res1, data[l++]);
      if (r % 2) res2 = Monoid::op(data[--r], res2);
      l /= 2; r /= 2;
    }
    return Monoid::op(res1, res2);
  }
};

struct MinQ {
  using type = int;
  static type id() { return INT_MAX; }
  static type op(const type &l, const type &r) { return min(l, r); }
};

struct MaxQ {
  using type = int;
  static type id() { return INT_MIN; }
  static type op(const type &l, const type &r) { return max(l, r); }
};

int T[128000];
int A[128000];
int B[128000];

void solve(ll X, ll K, vector<ll> r, ll Q, vector<ll> t, vector<ll> a) {
  T[0] = 0; A[0] = 0; B[0] = 0;
  T[K+1] = 11e8;
  REP(i,K) {
    T[i+1] = r[i];
    if (i % 2 == 0) A[i+1] = A[i] - (T[i+1] - T[i]);
    else A[i+1] = A[i] + (T[i+1] - T[i]);
    if (i % 2 == 0) B[i+1] = B[i] - (T[i+1] - T[i]);
    else B[i+1] = B[i] + (T[i+1] - T[i]);
    chmin(B[i+1], int(X));
    chmax(B[i+1], 0);
  }
  SegmentTree<MinQ> minq(K+1);
  SegmentTree<MaxQ> maxq(K+1);
  REP(i,K+1) minq.update(i, A[i]);
  REP(i,K+1) maxq.update(i, A[i]);
  REP(i,Q) {
    int it = upper_bound(T, T + K + 2, t[i]) - T - 1;
    int res = 0;
    int mi = minq.query(0, it + 1);
    int ma = maxq.query(0, it + 1);
    if (ma - mi >= X) res = B[it];
    else if (ma + a[i] >= X) res = a[i] + A[it] - (ma + a[i] - X);
    else if (mi + a[i] <= 0) res = a[i] + A[it] + (0 - mi - a[i]);
    else res = A[it] + a[i];
    if (it % 2 == 0) res -= t[i] - T[it];
    else res += t[i] - T[it];
    chmin(res, int(X));
    chmax(res, 0);
    cout << res << endl;
  }
}

int main() {
  locale loc(locale(), new yes_no);
  cout << boolalpha << setprecision(12) << fixed;
  cout.imbue(loc);
	ll Q;
	ll X;
	ll K;
	scanf("%lld", &X);
	scanf("%lld", &K);
	vector<ll> r(K-1+1);
	for (int i = 0 ; i <= K-1 ; i++) {
	  scanf("%lld", &r[i]);
	}
	scanf("%lld", &Q);
	vector<ll> a(Q-1+1);
	vector<ll> t(Q-1+1);
	for (int i = 0 ; i <= Q-1 ; i++) {
	  scanf("%lld", &t[i]);
	  scanf("%lld", &a[i]);
	}
	solve(X, K, r, Q, t, a);
	return 0;
}
