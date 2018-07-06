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

  int r, c, k, n;
  cin >> r >> c >> k >> n;
  int rr[n], cc[n];
  vector<int> amer(r), amec(c);
  rep(i, n) {
    cin >> rr[i] >> cc[i];
    amer[--rr[i]]++;
    amec[--cc[i]]++;
  }
  int ans = 0;
  rep(i, n) {
    if(amer[rr[i]]+amec[cc[i]] == k) ans--;
    if(amer[rr[i]]+amec[cc[i]] == k+1) ans++;
  }
  sort(all(amer));
  sort(all(amec));
  rep(i, r) {
    ans += upper_bound(all(amec), k-amer[i]) - lower_bound(all(amec), k-amer[i]);
  }
  cout << ans << endl;

  return 0;
}
