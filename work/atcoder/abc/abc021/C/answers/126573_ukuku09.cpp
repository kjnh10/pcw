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


  int n, a, b, m;
  cin >> n >> a >> b >> m;
  --a, --b;

  vector<int> g[101];
  rep(i, m) {
    int x, y;
    cin >> x >> y;
    --x, --y;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  vector<int> d(n, -1), c(n, -1);
  queue<int> q;
  d[a] = 0;
  c[a] = 1;
  q.push(a);
  while(q.size()) {
    int u = q.front(); q.pop();
    for(int v : g[u]) {
      if(d[v] == -1) {
	d[v] = d[u] + 1;
	c[v] = c[u];
	q.push(v);
      } else if(d[v] == d[u] + 1) {
	(c[v] += c[u]) %= mod;
      }
    }
  }
  cout << c[b] << endl;

  return 0;
}
