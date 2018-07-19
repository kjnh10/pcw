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

  int a[3], mx = 0, mn = 101;
  rep(i, 3) cin >> a[i], mx = max(mx, a[i]), mn = min(mn, a[i]);
  rep(i, 3) cout << (a[i] == mx ? 1 : (a[i] == mn) ? 3 : 2) << endl;

  return 0;
}
