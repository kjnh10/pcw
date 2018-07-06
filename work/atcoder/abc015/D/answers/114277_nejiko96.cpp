#include <cstdio>
#include <algorithm>

using namespace std;

#define REP(i,n)   for(int i=0; i<(int)(n); i++)
#define FOR(i,b,e) for(int i=(b); i<=(int)(e); i++)

const int W_MAX = 10000;
const int N_MAX = 50;
const int K_MAX = 50;

int W, N, K;
int A[N_MAX];
int B[N_MAX];

int dp[K_MAX + 1][W_MAX + 1];

void input() {
  scanf("%d%d%d", &W, &N, &K);
  REP(i, N) scanf("%d%d", A + i, B + i);
}

void solve() {
  REP(i, N) {
    for (int k = K; k > 0; k--) {
      for (int j = W; j >= A[i]; j--) {
        dp[k][j] = max(dp[k][j], dp[k - 1][j - A[i]] + B[i]);
      }
    }
  }
  printf("%d\n", dp[K][W]);
}

int main() {
  input();
  solve();
  return 0;
}
