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

template<int M, bool IsPrime = false>
class Modulo {
  using ll = long long;
  int n;
  static enable_if_t<IsPrime, ll> inv(ll a, ll p) {
    return (a == 1 ? 1 : (1 - p * inv(p%a, a)) / a + p);
  }
public:
  Modulo () : n(0) {;}
  Modulo (int m) : n(m) {
    if (n >= M) n %= M;
    else if (n < 0) n = (n % M + M) % M;
  }
  Modulo (ll m) {
    if (m >= M) m %= M;
    else if (m < 0) m = (m % M + M) % M;
    n = m;
  }
  explicit operator int() const { return n; }
  explicit operator ll() const { return n; }
  bool operator==(const Modulo &a) const { return n == a.n; }
  Modulo operator+=(const Modulo &a) { n += a.n; if (n >= M) n -= M; return *this; }
  Modulo operator-=(const Modulo &a) { n -= a.n; if (n < 0) n += M; return *this; }
  Modulo operator*=(const Modulo &a) { n = (ll(n) * a.n) % M; return *this; }
  Modulo operator+(const Modulo &a) const { Modulo res = *this; return res += a; }
  Modulo operator-(const Modulo &a) const { Modulo res = *this; return res -= a; }
  Modulo operator*(const Modulo &a) const { Modulo res = *this; return res *= a; }
  Modulo operator^(int n) const {
    if (n == 0) return Modulo(1);
    const Modulo a = *this;
    Modulo res = (a * a) ^ (n / 2);
    return n % 2 ? res * a : res;
  }
  enable_if_t<IsPrime, Modulo> operator/(const Modulo &a) const {
    return *this * inv(ll(a), M);
  }
};

const int mod = 1000000007;

using Mod = Modulo<mod, true>;

void solve(ll N, vector<string> S) {
  int color = 3;
  Mod res = 1;
  REP(i,N) {
    if (S[0][i] == S[1][i]) {
      if (color == 1) res *= Mod(2);
      if (color == 3) res *= Mod(3);
      color = 1;
    }
    else {
      ++i;
      if (color == 1) res *= Mod(2);
      if (color == 2) res *= Mod(3);
      if (color == 3) res *= Mod(6);
      color = 2;
    }
  }
  cout << int(res) << endl;
}

int main() {
  locale loc(locale(), new yes_no);
  cout << boolalpha << setprecision(12) << fixed;
  cout.imbue(loc);
	ll N;
	vector<string> S(2-1+1);
	scanf("%lld", &N);
	for (int i = 0 ; i <= 2-1 ; i++) {
	  cin >> S[i];
	}
	solve(N, S);
	return 0;
}
