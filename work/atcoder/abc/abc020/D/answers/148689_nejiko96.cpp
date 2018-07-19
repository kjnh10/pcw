#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define REP(i,n)   for(int i=0; i<(int)(n); i++)
#define FOR(i,b,e) for(int i=(b); i<=(int)(e); i++)
#define ALL(v)     (v.begin()), (v.end())

typedef long long ll;

const int MOD = 1000000007;

//------------------------------------------------------------------------------
vector<int> divisor(int n) {
  vector<int> res;
  for (int i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      res.push_back(i);
      if (i != n / i) res.push_back(n / i);
    }
  }
  return res;
}

//------------------------------------------------------------------------------
int N, K;

void solve() {
  vector<int> divs = divisor(K);
  sort(ALL(divs));
  int D = divs.size();

  vector<ll> sum(D);
  for (int i = D - 1; i >= 0; i--) {
    int M = N / divs[i];
    sum[i] = M + 1;
    sum[i] = sum[i] * M / 2 % MOD;
    for (int j = i + 1; j < D; j++) {
      if (divs[j] % divs[i] == 0) {
        sum[i] = ((sum[i] - sum[j] * divs[j] / divs[i]) % MOD + MOD) % MOD;
      }
    }
  }

  ll ans = 0;
  REP (i, D) {
    ans = (ans + sum[i]) % MOD;
  }
  ans = ans * K % MOD;
  printf("%lld\n", ans);
}

void input() {
  scanf("%d%d", &N, &K);
}

int main() {
  input();
  solve();
  return 0;
}
