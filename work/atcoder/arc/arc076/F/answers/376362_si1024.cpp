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

using P = pair<int,int>;

void solve(ll N, ll M, vector<ll> L, vector<ll> R) {
  vector<tuple<int,int,int>> vec;
  REP(i,N) vec.emplace_back(R[i], L[i], i);
  sort(ALL(vec));
  priority_queue<P, vector<P>, greater<P> > que;
  int piv = 0;
  int left = 0;
  int res = 0;
  for (int i = 1; i <= M; ++i) {
    while (piv < N && get<0>(vec[piv]) <= i) {
      que.emplace(get<1>(vec[piv]), get<2>(vec[piv]));
      ++piv;
    }
    if (que.empty()) ++left;
    else { que.pop(); ++res; }
  }
  while (piv < N) {
   que.emplace(get<1>(vec[piv]), get<2>(vec[piv]));
   ++piv;
  }
  // cout << left << endl;
  for (int i = 1; i <= left; ++i) {
    while (!que.empty() && que.top().first < i) que.pop();
    if (!que.empty()) { que.pop(); ++res; }
  }
  cout << N - res << endl;
}

int main() {
  locale loc(locale(), new yes_no);
  cout << boolalpha << setprecision(12) << fixed;
  cout.imbue(loc);
	ll M;
	ll N;
	scanf("%lld", &N);
	vector<ll> L(N-1+1);
	vector<ll> R(N-1+1);
	scanf("%lld", &M);
	for (int i = 0 ; i <= N-1 ; i++) {
	  scanf("%lld", &L[i]);
	  scanf("%lld", &R[i]);
	}
	solve(N, M, L, R);
	return 0;
}
