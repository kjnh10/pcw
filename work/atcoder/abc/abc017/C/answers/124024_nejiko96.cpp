#include <cstdio>
#include <algorithm>

using namespace std;

#define REP(i,n)   for(int i=0; i<(int)(n); i++)
#define FOR(i,b,e) for(int i=(b); i<=(int)(e); i++)

const int INF = 1000000007;

//------------------------------------------------------------------------------
#define LC(k)   (k * 2 + 1)
#define RC(k)   (k * 2 + 2)
#define M(l,r)  ((l + r) / 2)

const int ST_SIZE = 1 << 18;

int sz;
int dat[ST_SIZE];

void rmq_init(int n) {
  sz = n;
}

void add_at(int a, int b, int x, int k, int l, int r) {
  if (r <= a || b <= l) return;
  if (a <= l && r <= b) {
    dat[k] += x;
    return;
  }
  add_at(a, b, x, LC(k), l, M(l, r));
  add_at(a, b, x, RC(k), M(l, r), r);
}

void add(int a, int b, int x) {
  add_at(a, b, x, 0, 0, sz);
}

int query_sub(int k, int l, int r) {
  if (r - l == 1) return dat[k];
  int vl = query_sub(LC(k), l, M(l, r));
  int vr = query_sub(RC(k), M(l, r), r);
  return min(vl, vr) + dat[k];
}

int query() {
  return query_sub(0, 0, sz);
}

//------------------------------------------------------------------------------
const int N_MAX = 100000;

int N, M;
int l[N_MAX];
int r[N_MAX];
int s[N_MAX];

void input() {
  scanf("%d%d", &N, &M);
  REP(i, N) scanf("%d%d%d", l + i, r + i, s + i);
}

void solve() {
  rmq_init(M);
  int total = 0;
  REP(i, N) {
    add(l[i] - 1, r[i], s[i]);
    total += s[i];
  }
  printf("%d\n", total - query());
}

int main() {
  input();
  solve();
  return 0;
}
