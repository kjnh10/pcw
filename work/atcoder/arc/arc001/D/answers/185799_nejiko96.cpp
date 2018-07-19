#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

#define REP(i,n)   for(int i=0; i<(int)(n); i++)
#define FOR(i,b,e) for(int i=(b); i<=(int)(e); i++)

const double INF = 1000000000;
const int N_MAX = 200000;

int N;
int start, goal;
int l[N_MAX + 1];
int r[N_MAX + 1];

void solve() {
  l[N] = r[N] = goal;
  double ans = 0;
  int sy = 0; double sx = start;
  while (sy < N) {
    double ldeg = -INF, rdeg = INF;
    int ly = sy, ry = sy;
    FOR(y, sy + 1, N) {
      double lldeg = (l[y] - sx) / (y - sy);
      if (lldeg > ldeg) {
        ldeg = lldeg; ly = y;
      }
      double rrdeg = (r[y] - sx) / (y - sy);
      if (rrdeg < rdeg) {
        rdeg = rrdeg; ry = y;
      }
      if (ldeg >= rdeg) {
        if (ly < ry) {
          ans += hypot(l[ly] - sx, ly - sy);
          sy = ly; sx = l[ly];
        } else {
          ans += hypot(r[ry] - sx, ry - sy);
          sy = ry; sx = r[ry];
        }
        break;
      }
    }
  }

  printf("%.10f\n", ans);
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
