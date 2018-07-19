#include <cstdio>
#include <algorithm>
#include <cstdlib>

using namespace std;

#define REP(i,n)   for(int i=0; i<(int)(n); i++)
#define FOR(i,b,e) for(int i=(b); i<=(int)(e); i++)

#define ROW(x, y) ((x) + (y)) / 2;
#define COL(x, y) ((x) - (y)) / 2;

const int R_MAX = 500;
const int C_MAX = 500;
const int K_MAX = 500;
const int X_MAX = R_MAX + C_MAX;

int R, C, K;
char s[R_MAX][C_MAX + 1];

int T;
int len[X_MAX];
int cnta[X_MAX];
int cntb[X_MAX];

void input() {
  scanf("%d%d%d", &R, &C, &K);
  REP(i, R) scanf("%s", s[i]);
}

void solve() {
  T = 2 * K - 1;
  int ans = 0;
  FOR(y, -C, R) {
    for (int x = abs(y); x < R + C; x += 2) {
      int i = ROW(x, y);
      int j = COL(x, y);
      // printf("y:%d, x:%d, i:%d, j:%d\n", y, x, i, j);
      if (i >= R || j >= C) break;
      len[x]++;
      if (s[i][j] == 'o') { cnta[x]++; cntb[x]++; }
      if (len[x] > K && s[i - K][j + K] == 'o') cnta[x]--;
      if (len[x] > K - 1 && s[i - K + 1][j + K - 1] == 'o') cntb[x]--;
      if (j >= K - 1 && i >= T - 1) {
        bool ok = true;
        REP(t, T) {
          if (t % 2 == 0 && len[x - t] >= K && cnta[x - t] == K) continue;
          if (t % 2 > 0 && len[x - t] >= K - 1 && cntb[x - t] == K - 1) continue;
          ok = false;
        }
        if (ok) { ans++; }
      }
    }
  }
  printf("%d\n", ans);
}

int main() {
  input();
  solve();
  return 0;
}
