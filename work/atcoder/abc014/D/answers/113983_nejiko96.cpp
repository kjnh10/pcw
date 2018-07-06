#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define REP(i,n)   for(int i=0; i<(int)(n); i++)
#define FOR(i,b,e) for(int i=(b); i<=(int)(e); i++)

const int INF = 1000000000;

//------------------------------------------------------------------------------
#define SZ      (sz * 2 - 1)
#define LF(i)   (i + sz - 1)
#define PA(k)   ((k - 1) / 2)
#define LC(k)   (k * 2 + 1)
#define RC(k)   (k * 2 + 2)
#define M(l,r)  ((l + r) / 2)

const int ST_SIZE = (1 << 19) - 1;    // max(sz) * 2 - 1

int sz;
pair<int, int> dep[ST_SIZE];

void rmq_init(int n) {
  sz = 1;
  while (sz < n) sz <<= 1;
  fill(dep, dep + SZ, make_pair(INF, 0));
}

void update(int i, int a) {
  int k = LF(i);
  dep[k].first = a;
  dep[k].second = i;
  while (k > 0) {
    k = PA(k);
    dep[k] = min(dep[LC(k)], dep[RC(k)]);
  }
}

pair<int, int> query_sub(int a, int b, int k, int l, int r) {
  if (r <= a || b <= l) {
    return make_pair(INF, 0);
  }
  if (a <= l && r <= b) {
    return dep[k];
  }
  else {
    pair<int, int> vl = query_sub(a, b, LC(k), l, M(l, r));
    pair<int, int> vr = query_sub(a, b, RC(k), M(l, r), r);
    return min(vl, vr);
  }
}

int query(int a, int b) {
  return query_sub(a, b, 0, 0, sz).second;
}

//------------------------------------------------------------------------------
const int V_MAX = 100000;
const int W_MAX = V_MAX * 2 - 1;

int V;
vector<int> G[V_MAX];
int root = 0;

int vs[W_MAX];
int depth[W_MAX];
int id[V_MAX];

void dfs(int v, int p, int d, int &k) {
  id[v] = k;
  vs[k] = v;
  depth[k++] = d;
  REP(i, G[v].size()) {
    if (G[v][i] != p) {
      dfs(G[v][i], v, d + 1, k);
      vs[k] = v;
      depth[k++] = d;
    }
  }
}

// struct dfs_st {
//   int v;
//   int p;
//   int d;
// };

// dfs_st st[V_MAX];

// void dfs_norec() {
//   fill(id, id + V, -1);
//   int k = 0, t = 0;
//   st[t++] = (dfs_st) { root, -1, 0 };
//   while (t > 0) {
//     dfs_st &x = st[t - 1];
//     if (id[x.v] < 0) id[x.v] = k;
//     vs[k] = x.v;
//     depth[k++] = x.d;
//     bool added = false;
//     REP(i, G[x.v].size()) {
//       int u = G[x.v][i];
//       if (u == x.p || id[u] >= 0) continue;
//       st[t++] = (dfs_st) { u, x.v, x.d + 1 };
//       added = true;
//       break;
//     }
//     if (!added) t--;
//   }
// }

void lca_init() {
  int k = 0;
  dfs(root, -1, 0, k);
  // dfs_norec();

  int W = V * 2 - 1;
  rmq_init(W);
  REP(i, W) update(i, depth[i]);

  // printf("vs: ");
  // REP(i, W) printf("%d%c", vs[i], i + 1 == W ? '\n' : ' ');
  // printf("depth: ");
  // REP(i, W) printf("%d%c", depth[i], i + 1 == W ? '\n' : ' ');
  // printf("id: ");
  // REP(i, V) printf("%d%c", id[i], i + 1 == V ? '\n' : ' ');
}

int lca(int u, int v) {
  return vs[query(min(id[u], id[v]), max(id[u], id[v]) + 1)];
}

//------------------------------------------------------------------------------
const int E_MAX = 100000;
const int Q_MAX = 100000;

int E;
int N, Q;
int x[E_MAX];
int y[E_MAX];
int a[Q_MAX];
int b[Q_MAX];

void build_graph() {
  REP(i, E) {
    G[x[i] - 1].push_back(y[i] - 1);
    G[y[i] - 1].push_back(x[i] - 1);
  }
}

void input() {
  scanf("%d", &N);
  V = N;
  E = N - 1;
  REP(i, E) scanf("%d%d", x + i, y + i);
  scanf("%d", &Q);
  REP(i, Q) scanf("%d%d", a + i, b + i);
}

void solve() {
  build_graph();
  lca_init();
  REP(i, Q) {
    int u = a[i] - 1, v = b[i] - 1;
    int p = lca(u, v);
    printf("%d\n", depth[id[u]] + depth[id[v]] - 2 * depth[id[p]] + 1);
  }
}

int main() {
  input();
  solve();
  return 0;
}
