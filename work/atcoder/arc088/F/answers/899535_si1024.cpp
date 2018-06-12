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

vector<int> g[100010];
bool visited[100010];

pair<int,bool> dfs1(int v) {
  visited[v] = true;
  int res = 0;
  int d = 0;
  for (int i: g[v]) {
    if (visited[i]) continue;
    ++d;
    res += dfs1(i).first;
  }
  res += d / 2;
  return make_pair(res, d % 2 == 1);
}

pair<int,int> dfs2(int v, int limit) {
  visited[v] = true;
  int sum = 0;
  multiset<int> s;
  for (int i: g[v]) {
    if (visited[i]) continue;
    auto r = dfs2(i, limit);
    sum += r.first;
    s.insert(r.second + 1);
  }
  multiset<int> rest;
  while (!s.empty()) {
    auto it = prev(end(s));
    int a = *it;
    s.erase(it);
    if (a > limit) { s.insert(a - limit); ++sum; continue; }
    if (s.empty()) { rest.insert(a); break; }
    it = s.upper_bound(limit - a);
    if (it == begin(s)) { rest.insert(a); continue; }
    sum++;
    s.erase(prev(it));
  }
  if (!rest.empty()) sum += int(rest.size()) - 1;
  int len = rest.empty() ? 0 : *begin(rest);
  // cout << v << " " << limit << " " << sum << " " << len << endl;
  return make_pair(sum, len);
}

void solve(ll N, vector<ll> a, vector<ll> b) {
  REP(i,N-1) {
    int s = a[i] - 1, t = b[i] - 1;
    g[s].push_back(t);
    g[t].push_back(s);
  }
  memset(visited, 0, sizeof(visited));
  auto r = dfs1(0);
  int res = r.first + r.second;
  int lb = 0, ub = 1e6;
  // memset(visited, 0, sizeof(visited));
  // auto rr = dfs2(0, 2);
  // cout << rr.first << " " << rr.second << endl;
  // return;
  while (ub - lb > 1) {
    int mid = (lb + ub) / 2;
    memset(visited, 0, sizeof(visited));
    auto r = dfs2(0, mid);
    int c = r.first + (r.second > 0);
    if (c > res) lb = mid; else ub = mid;
  }
  cout << res << " " << ub << endl;
}

int main() {
  locale loc(locale(), new yes_no);
  cout << boolalpha << setprecision(12) << fixed;
  cout.imbue(loc);
	ll N;
	scanf("%lld", &N);
	vector<ll> b((N-1)-1+1);
	vector<ll> a((N-1)-1+1);
	for (int i = 0 ; i <= (N-1)-1 ; i++) {
	  scanf("%lld", &a[i]);
	  scanf("%lld", &b[i]);
	}
	solve(N, a, b);
	return 0;
}
