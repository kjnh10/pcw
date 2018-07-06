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

  int n, m, x, y;
  cin >> n >> m >> x >> y;
  vector<int> a(n), b(m);
  rep(i, n) cin >> a[i];
  rep(i, m) cin >> b[i];
  int air = 0, now = 0;
  int cnt = 0;
  while(1) {
    auto i = lower_bound(all(a), now);
    if(i == a.end()) break;
    now = *i + x;
    auto j = lower_bound(all(b), now);
    if(j == b.end()) break;
    now = *j + y;
    cnt++;
  }
  cout << cnt << endl;

  return 0;
}
