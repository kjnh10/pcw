#include <bits/stdc++.h>

using namespace std;

#define int long long
#define all(v) begin(v), end(v)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define reps(i, s, n) for(int i = (int)(s); i < (int)(n); i++)
#define min(...) min({__VA_ARGS__})
#define max(...) max({__VA_ARGS__})

const int inf = 1LL << 55;
const int mod = 1e9 + 7;

int n;
vector<int> g[22];

int dfs(int v)
{
  if(g[v].size() == 0) return 1;
  int mx = -inf, mn = inf;
  for(int u : g[v]) {
    int s = dfs(u);
    mx = max(mx, s);
    mn = min(mn, s);
  }
  return mx + mn + 1;
}

signed main()
{
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(12);

  cin >> n;
  reps(i, 1, n) {
    int b;
    cin >> b;
    g[--b].push_back(i);
  }
  cout << dfs(0) << endl;

  return 0;
}
