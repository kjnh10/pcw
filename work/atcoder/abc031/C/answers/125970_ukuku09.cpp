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

  int n;
  cin >> n;
  int a[n];
  rep(i, n) cin >> a[i];
  int ans = -inf;
  rep(i, n) {
    int amx = -inf;
    int temp = -inf;
    rep(j, n) if(i != j) {
      int tsum = 0, asum = 0;
      reps(k, min(i, j), max(i, j)+1) {
	if((k-min(i, j))%2) asum += a[k];
	else tsum += a[k];
      }
      if(amx < asum) amx = asum, temp = tsum;
    }
    ans = max(ans, temp);
  }
  cout << ans << endl;

  return 0;
}
