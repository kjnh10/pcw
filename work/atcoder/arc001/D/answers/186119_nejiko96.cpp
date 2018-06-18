#include <cstdio>
#include <cmath>

using namespace std;

#define REP(i,n)   for(int i=0; i<(int)(n); i++)
#define FOR(i,b,e) for(int i=(b); i<=(int)(e); i++)

//------------------------------------------------------------------------------
typedef long long ll;

struct P {
  ll x;
  ll y;
  P() {}
  P(ll x, ll y) : x(x), y(y) {}
  P operator - (P p) {
    return P(x - p.x, y - p.y);
  }
  bool operator < (const P &p) const {
    if (x != p.x) return x < p.x;
    return y < p.y;
  }
  ll det(P p) {
    return x * p.y - y * p.x;
  }
  ll dot(P p) {
    return x * p.x + y * p.y;
  }
  double dist() {
    return hypot(x, y);
  }
};

//------------------------------------------------------------------------------
const int N_MAX = 200000;

int N;
int start, goal;
int l[N_MAX + 1];
int r[N_MAX + 1];

P lv[N_MAX + 1];
P rv[N_MAX + 1];

void solve() {
  l[0] = r[0] = start;
  l[N] = r[N] = goal;
  int ls = 0, lt = 0, rs = 0, rt = 0;
  REP(y, 2) {
    lv[lt++] = P(l[y], y);
    rv[rt++] = P(r[y], y);
  }
  double ans = 0;
  FOR(y, 2, N) {
    P lp = P(l[y], y);
    while (lt - ls > 1 && (lv[lt - 1] - lv[lt - 2]).det(lp - lv[lt - 1]) <= 0) lt--;
    lv[lt++] = lp;
    P rp = P(r[y], y);
    while (rt - rs > 1 && (rv[rt - 1] - rv[rt - 2]).det(rp - rv[rt - 1]) >= 0) rt--;
    rv[rt++] = rp;
    // puts("");
    // puts("lv:"); FOR(i, ls, lt - 1) printf("[%d, %d]%c", lv[i].y, lv[i].x, i == lt - 1 ? '\n' : ' ');
    // puts("rv:"); FOR(i, rs, rt - 1) printf("[%d, %d]%c", rv[i].y, rv[i].x, i == rt - 1 ? '\n' : ' ');
    while (lt - ls > 1 && rt - rs > 1) {
      P p0 = lv[ls], l1 = lv[ls + 1], r1 = rv[rs + 1];
      if ((r1 - p0).det(l1 - p0) >= 0) break;
      if (l1.y < r1.y) {
        ans += (l1 - p0).dist();
        rv[rs] = lv[++ls];
      } else {
        ans += (r1 - p0).dist();
        lv[ls] = rv[++rs];
      }
      // printf("ans:%f\n", ans);
    }
  }
  // puts("");
  // puts("lv:"); FOR(i, ls, lt - 1) printf("[%d, %d]%c", lv[i].y, lv[i].x, i == lt - 1 ? '\n' : ' ');
  // puts("rv:"); FOR(i, rs, rt - 1) printf("[%d, %d]%c", rv[i].y, rv[i].x, i == rt - 1 ? '\n' : ' ');
  ans += (lv[lt - 1] - lv[ls]).dist();
  printf("%.14f\n", ans);
}

void input() {
  scanf("%d", &N);
  scanf("%d%d", &start, &goal);
  REP(i, N + 1) scanf("%d%d", l + i, r + i);
}

int main() {
  input();
  solve();
  return 0;
}
