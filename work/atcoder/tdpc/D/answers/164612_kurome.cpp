#include <bits/stdc++.h>

using namespace std;

#define FOR(i,s,e) for(int (i)=(s);(i)<(int)(e);(i)++)
#define REP(i,e) FOR(i,0,e)

#define all(o) (o).begin(), (o).end()
#define psb(x) push_back(x)

typedef long long ll;

const int N = 100;
const double eps = 1e-100;
int n, n2, n3, n5;
ll d;
double dp[N+1][60][40][30];
int idx[6][3] = {
  {0,0,0},
  {1,0,0},
  {0,1,0},
  {2,0,0},
  {0,0,1},
  {1,1,0}
};

int main() {
  scanf("%d%lld ", &n, &d);
  n2 = n3 = n5 = 0;
  while (d%2LL==0) {d /= 2LL; n2++;};
  while (d%3LL==0) {d /= 3LL; n3++;};
  while (d%5LL==0) {d /= 5LL; n5++;};
  if (d > 1LL) {
    puts("0");
    return 0;
  }

  memset(dp, 0, sizeof(dp));
  dp[0][0][0][0] = 1;

  REP(i,n) REP(j,n2+1) REP(k,n3+1) REP(l,n5+1) if (dp[i][j][k][l] > eps) {
    REP(m,6) {
      int jj = min(j + idx[m][0], n2);
      int kk = min(k + idx[m][1], n3);
      int ll = min(l + idx[m][2], n5);
      dp[i+1][jj][kk][ll] += dp[i][j][k][l] / 6;
    }
  }
  printf("%.8f\n", dp[n][n2][n3][n5]);
  return 0;
}