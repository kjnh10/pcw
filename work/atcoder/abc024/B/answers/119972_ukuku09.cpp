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

  int n, t;
  cin >> n >> t;
  int a[n];
  int sum = 0;
  rep(i, n) {
    cin >> a[i];
    if(!i) continue;
    if(a[i] - a[i-1] >= t) sum += t;
    else sum += a[i] - a[i-1];
  }
  cout << sum + t << endl;

  return 0;
}
