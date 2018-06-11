#include "bits/stdc++.h"

using namespace std;

const int INF = 1e9 + 7;

int n;
int s[100], dp[100][10001];

int dfs(int now, int score)
{
  if(n == now) {
    return score % 10 ? score : 0;
  }
  if (~dp[now][score]) return dp[now][score];
  return dp[now][score] = max(dfs(now + 1, score), dfs(now + 1, score + s[now]));
}

void solve()
{
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> s[i];
  }
  sort(s, s + n);
  memset(dp, -1, sizeof dp);
  cout << dfs(0, 0) << "\n";
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  solve();
}