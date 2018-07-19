#include <cstdio>

#define REP(i,n)   for(int i=0; i<(int)(n); i++)
#define FOR(i,b,e) for(int i=(b); i<=(int)(e); i++)

const int MOD = 1000000007;
const int N_MAX = 100000;
const int M_MAX = 100000;

int N, M;
int f[N_MAX];

bool used[M_MAX + 1];
int dp[N_MAX + 1];
int S[N_MAX + 1];

void input() {
  scanf("%d%d", &N, &M);
  REP(i, N) scanf("%d", f + i);
}

void solve() {
  dp[0] = 1;
  S[0] = 1;
  int k = -1;
  REP(i, N) {
    if (used[f[i]]) {
      while (f[++k] != f[i]) used[f[k]] = false;
    }
    used[f[i]] = true;
    dp[i + 1] = k >= 0 ? (S[i] + MOD - S[k]) % MOD : S[i];
    S[i + 1] = (S[i] + dp[i + 1]) % MOD;
  }
  printf("%d\n", dp[N]);
}

int main() {
  input();
  solve();
  return 0;
}
