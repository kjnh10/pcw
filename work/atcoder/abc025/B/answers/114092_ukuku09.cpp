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

  int n, a, b;
  cin >> n >> a >> b;
  int pos = 0;
  rep(i, n) {
    string s;
    int d;
    cin >> s >> d;
    d = min(max(d, a), b);
    if(s == "East") pos += d;
    else pos -= d;
  }
  if(pos == 0) cout << 0 << endl;
  else cout << (pos < 0 ? "West" : "East") << " " << abs(pos) << endl;

  return 0;
}
