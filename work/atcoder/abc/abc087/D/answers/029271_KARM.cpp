#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <iomanip>
#include <cassert>
#include <cstdio>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
using namespace std;

#define db(x) cerr << #x << " = " << x << endl;

typedef long long   ll;
typedef long double ld;
typedef pair < int, int > pii;
typedef pair < ll,  ll  > pll;

const ll   MOD       = 1000000007;
const ll   INF       = 1000000007ll*1000000007ll;
const ll   N         = 1000002;
const ll   logN      = 20;
const ld   PI        = acos(-1);
const ll   HashPrime = 31;

inline void No() {
    cout << "No\n";
}
inline void Yes() {
    cout << "Yes\n";
}

#define fi first
#define se second

ll l, r, d;
ll n, m;
ll ans[N];
bool mark[N];
vector < pll > g[N];

void dfs(int v) {
  mark[v] = true;
  for (int i = 0; i < g[v].size(); ++i) {
    ll to = g[v][i].first, len = g[v][i].second;
    if (ans[to] == INF) {
      ans[to] = ans[v] + len;
    }
    if (ans[to] != ans[v] + len) {
      No();
      exit(0);
    }
    if (!mark[to]) {
      dfs(to);
    }
  }
}

void solve() {
  fill(ans, ans+N, INF);
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    cin >> l >> r >> d;
    g[l].push_back({r, d});
    g[r].push_back({l, -d});
  }
  for (int i = 1; i <= n; ++i) {
    if (!mark[i]) {
      ans[i] = 0;
      dfs(i);
    }
  }
  Yes();
}

int main() {
  ll t = 1;
//  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
