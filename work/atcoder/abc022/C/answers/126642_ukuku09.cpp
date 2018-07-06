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

signed main()
{
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(12);

  int n, m;
  cin >> n >> m;
  int g[333][333];
  fill(g[0], g[333], inf);
  rep(i, n) g[i][i] = 0;
  int h[333];
  fill(h, h + 333, inf);
  rep(i, m) {
    int u, v, l;
    cin >> u >> v >> l;
    u--, v--;
    if(u > v) swap(u, v);
    if(u > 0) g[u][v] = g[v][u] = l;
    else h[v] = l;
  }
  rep(i, n) rep(j, n) rep(k, n) {
    g[j][k] = min(g[j][k], g[j][i] + g[i][k]);
  }
  int ans = inf;
  rep(i, n) reps(j, i+1, n) {
    ans = min(ans, h[i] + g[i][j] + h[j]);
  }
  cout << (ans == inf ? -1 : ans) << endl;

  return 0;
}
