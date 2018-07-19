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

void solve(ll N, ll M, vector<ll> a, vector<ll> b, vector<ll> c) {
  vector<vector<int>> X(N, vector<int>(N, 1e9));
  REP(i,N) X[i][i] = 0;
  REP(i,M) {
    X[a[i]-1][b[i]-1] = c[i];
    X[b[i]-1][a[i]-1] = c[i];
  }
  auto Y = X;
  REP(k,N) REP(i,N) REP(j,N)
    chmin(Y[i][j], Y[i][k] + Y[k][j]);
  int res = 0;
  REP(i,N) REP(j,N)
    if (X[i][j] < 1e9 && X[i][j] > Y[i][j]) ++res;
  cout << res / 2 << endl;
}

int main() {
  locale loc(locale(), new yes_no);
  cout << boolalpha << setprecision(12) << fixed;
  cout.imbue(loc);
	ll N;
	ll M;
	scanf("%lld", &N);
	scanf("%lld", &M);
	vector<ll> a(M-1+1);
	vector<ll> c(M-1+1);
	vector<ll> b(M-1+1);
	for (int i = 0 ; i <= M-1 ; i++) {
	  scanf("%lld", &a[i]);
	  scanf("%lld", &b[i]);
	  scanf("%lld", &c[i]);
	}
	solve(N, M, a, b, c);
	return 0;
}
