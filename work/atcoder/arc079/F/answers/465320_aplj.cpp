#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <numeric>
#include <algorithm>
#include <bitset>
#include <complex>
#include <array>
#include <list>
#include <stack>
#include <valarray>

using namespace std;

typedef unsigned uint;
typedef long long Int;
typedef unsigned long long UInt;

const int INF = 1001001001;
const Int INFLL = 1001001001001001001LL;

template<typename T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<typename T> void chmin(T& a, T b) { if (a > b) a = b; }
template<typename T> void chmax(T& a, T b) { if (a < b) a = b; }
int in() { int x; scanf("%d", &x); return x; }
double fin() { double x; scanf("%lf", &x); return x; }
Int lin() { Int x; scanf("%lld", &x); return x; }

struct edge {
  int src, dst;
  edge(int s, int d) : src(s), dst(d) { }
};
typedef vector<edge> edges;
typedef vector<edges> graph;

#define VAR(x) ((x) << 1)
#define NOT(x) ((x) ^ 1)
void visit(int v, const graph &g,
    vector<int> &ord, vector<int> &num, int k) {
  if (num[v] >= 0) return;
  num[v] = k;
  for (int i = 0; i < g[v].size(); ++i)
    visit(g[v][i].dst, g, ord, num, k);
  ord.push_back(v);
}
typedef pair<int,int> clause;
bool two_satisfiability(int m, const vector<clause> &cs) {
  int n = m * 2; // m positive vars and m negative vars
  graph g(n), h(n);
  for (int i = 0; i < cs.size(); ++i) {
    int u = cs[i].first, v = cs[i].second;
    g[NOT(u)].push_back( edge(NOT(u), v) );
    g[NOT(v)].push_back( edge(NOT(v), u) );
    h[v].push_back( edge(v, NOT(u)) );
    h[u].push_back( edge(u, NOT(v)) );
  }
  vector<int> num(n, -1), ord, dro;
  for (int i = 0; i < n; ++i)
    visit(i, g, ord, num, i);
  reverse(ord.begin(), ord.end());
  fill(num.begin(), num.end(), -1);
  for (int i = 0; i < n; ++i)
    visit(ord[i], h, dro, num, i);
  for (int i = 0; i < n; ++i)
    if (num[i] == num[NOT(i)])
      return false;
  return true;
}

vector<int> to[200050];
int rev[200050], inC[200050], vis[200050], G[200050], T[200050];
int PG[200050][2];

int dfs1(int u) {
  if (vis[u] == 1) {
    return u;
  }
  vis[u] = 1;
  int t = dfs1(rev[u]);
  if (t >= 0) {
      return t;
  }
  return -1;
}

void calc(int u) {
  if (to[u].empty()) {
    G[u] = 0;
    return;
  }

  for (const int v : to[u]) {
    calc(v);
  }
  for (const int v : to[u]) {
    T[G[v]] = 1;
  }
  for (int g = 0; ; ++g) {
    if (T[g] == 0) {
      G[u] = g;
      break;
    }
  }
  for (const int v : to[u]) {
    T[G[v]] = 0;
  }
}

int main() {
  int N = in();
  for (int i = 0; i < N; ++i) {
    int p = in() - 1;
    to[p].push_back(i);
    rev[i] = p;
  }

  vector<int> cyc;
  const int c0 = dfs1(0);
  for (int u = c0; ;) {
    inC[u] = 1;
    cyc.push_back(u);
    u = rev[u];
    if (u == c0) {
      break;
    }
  }
  reverse(cyc.begin(), cyc.end());

  for (int i = 0; i < N; ++i) {
    if (inC[i]) {
      for (const int u : to[i]) {
        if (!inC[u]) {
          calc(u);
        }
      }
    }
  }

  const int M = cyc.size();
  for (int i = 0; i < M; ++i) {
    int c = cyc[i];
    for (const int u : to[c]) {
      if (!inC[u]) {
        T[G[u]] = 1;
      }
    }
    for (int g = 0, k = 0; k < 2; ++g) {
      if (T[g] == 0) {
        PG[i][k++] = g;
      }
    }
    for (const int u : to[c]) {
      if (!inC[u]) {
        T[G[u]] = 0;
      }
    }
  }

  vector<clause> cs;
  for (int i = 0; i < M; ++i) {
    int c = i, nxt = (i + 1) % M;
    int r = PG[c][0];
    int k = -1;
    for (int j = 0; j < 2; ++j) {
      if (PG[nxt][j] == r) {
        k = j;
      }
    }
    if (k < 0) {
      cs.emplace_back(VAR(c), VAR(c));
    } else {
      cs.emplace_back(VAR(c), k == 0 ? VAR(nxt) : NOT(VAR(nxt)));
    }

    for (int a = 0; a < 2; ++a) {
      for (int b = 0; b < 2; ++b) {
        if (PG[c][a] == PG[nxt][b]) {
          cs.emplace_back(a == 0 ? NOT(VAR(c)) : VAR(c), b == 0 ? NOT(VAR(nxt)) : VAR(nxt));
        }
      }
    }
  }

  puts(two_satisfiability(M, cs) ? "POSSIBLE" : "IMPOSSIBLE");

  return 0;
}
