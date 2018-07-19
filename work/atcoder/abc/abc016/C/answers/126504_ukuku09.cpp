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
  int g[n][n];
  rep(i, n) rep(j, n) g[i][j] = inf;
  rep(i, n) g[i][i] = 0;
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    g[a][b] = g[b][a] = 1;
  }
  rep(i, n) rep(j, n) rep(k, n) {
    g[j][k] = min(g[j][k], g[j][i] + g[i][k]);
  }
  rep(i, n) {
    int cnt = 0;
    rep(j, n) if(g[i][j] == 2) cnt++;
    cout << cnt << endl;
  }

  return 0;
}
