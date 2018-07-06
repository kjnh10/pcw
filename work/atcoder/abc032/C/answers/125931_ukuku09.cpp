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

  int n, k;
  cin >> n >> k;
  int s[n];
  bool flag = false;
  rep(i, n) cin >> s[i], flag |= (s[i] == 0);

  if(flag) {
    cout << n << endl;
    return 0;
  }
  if(k == 0) {
    cout << 0 << endl;
    return 0;
  }

  int pro = 1, ans = 0;
  int i, j;
  for(i = 0, j = 0; i < n; i++) {
    pro *= s[i];
    if(pro > k) {
      ans = max(ans, i-j);
      while(pro > k) pro /= s[j++];
    }
  }
  if(pro <= k) ans = max(ans, i-j);
  cout << ans << endl;

  return 0;
}
