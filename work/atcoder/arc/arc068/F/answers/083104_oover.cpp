#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define FORD(i,b,a) for (int i = (int)(b) - 1; i >= a; --i)
#define REP(i,N) FOR(i,0,N)
#define st first
#define nd second
#define pb push_back

typedef pair<int, int> PII;
typedef long long LL;

const int MOD = 1000000007;
LL DP[2005][2005];

int main() {
  int N, K;
  scanf("%d%d", &N, &K);
  FOR(i,1,N-K+2) DP[N-K+1][i] = 1;
  FOR(i,N-K+2,N+1) {
    LL su = 0;
    REP(j,i+1) {
      su += DP[i-1][j];
      DP[i][j] = su % MOD;
    }
  }
  LL res = DP[N][N];
  REP(i,max(0, N-K-1)) res = 2 * res % MOD;
  printf("%lld\n", res);
}
