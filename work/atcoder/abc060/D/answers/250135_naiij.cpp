#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int main() {
  map <int, int> dp[2];
  int n, m, t = 0;
  scanf("%d %d", &n, &m);
  dp[t][0] = 0;
  for (int i = 0; i < n; i ++) {
    t ^= 1;
    dp[t].clear();
    int w, v;
    scanf("%d %d", &w, &v);
    for (auto x : dp[t ^ 1]) {
      int wt = x.first, va = x.second;
      dp[t][wt] = max(dp[t][wt], va);
      if (wt + w <= m)
        dp[t][wt + w] = max(dp[t][wt + w], va + v);
    }
  }
  int ans = 0;
  for (auto x : dp[t])
    ans = max(ans, x.second);
  cout << ans << endl;
  return 0;
}