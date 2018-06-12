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
  string_type do_truename()  const { return "Yes"; }
  string_type do_falsename() const { return "No"; }
};

const int mod = 1000000007;

struct Mod {
  int n;
  Mod () : n(0) {;}
  Mod (int m) : n(m) {
    if (n >= mod) n %= mod;
    else if (n < 0) n = (n % mod + mod) % mod;
  }
  operator int() { return n; }
};

bool operator==(Mod a, Mod b) { return a.n == b.n; }
Mod operator+=(Mod &a, Mod b) { a.n += b.n; if (a.n >= mod) a.n -= mod; return a; }
Mod operator-=(Mod &a, Mod b) { a.n -= b.n; if (a.n < 0) a.n += mod; return a; }
Mod operator*=(Mod &a, Mod b) { a.n = ((long long)a.n * b.n) % mod; return a; }
Mod operator+(Mod a, Mod b) { return a += b; }
Mod operator-(Mod a, Mod b) { return a -= b; }
Mod operator*(Mod a, Mod b) { return a *= b; }
Mod operator^(Mod a, int n) {
  if (n == 0) return Mod(1);
  Mod res = (a * a) ^ (n / 2);
  if (n % 2) res = res * a;
  return res;
}

ll inv(ll a, ll p) {
  return (a == 1 ? 1 : (1 - p * inv(p%a, a)) / a + p);
}
Mod operator/(Mod a, Mod b) { return a * Mod(inv(b, mod)); }

#define MAX_N 1024000

Mod fact[MAX_N], factinv[MAX_N];
void init() {
  fact[0] = Mod(1); factinv[0] = 1;
  REP(i,MAX_N-1) {
    fact[i+1] = fact[i] * Mod(i+1);
    factinv[i+1] = factinv[i] / Mod(i+1);
  }
}
Mod comb(int a, int b) {
  return fact[a] * factinv[b] * factinv[a-b];
}

Mod dp_ptr[2048000];
Mod sum_ptr[2048000];

void solve(ll n) {
  Mod *dp = dp_ptr + 1024000;
  Mod *sum = sum_ptr + 1024000;
  // dp[0] = 1;
  // dp[1] = n;
  // dp[2] = Mod(n) * Mod(n);
  // sum[1] = sum[0] + dp[0];
  // sum[2] = sum[1] + dp[1];
  // sum[3] = sum[2] + dp[2];
  for (int i = -1010000; i < 1010000; ++i) {
    if (i <= 0) dp[i] = 1;
    else if (i == 1) dp[i] = n;
    else if (i == 2) dp[i] = Mod(n) * Mod(n);
    else dp[i] = dp[i-1] + Mod(n - 1) * Mod(n - 1) + (sum[i-2] - sum[i-2-(n-1)]);
    sum[i+1] = sum[i] + dp[i];
  }
  cout << dp[n] << endl;
}

int main() {
  locale loc(locale(), new yes_no);
  cout << boolalpha << setprecision(12) << fixed;
  cout.imbue(loc);
	ll n;
	scanf("%lld", &n);
	solve(n);
	return 0;
}
