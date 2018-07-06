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
  string s;
  cin >> n >> s;
  string t = "b";
  for(int i = 1; i < 100; i++) {
    if(t.size() > s.size()) {
      cout << -1 << endl;
      return 0;
    }
    if(t == s) {
      cout << i-1 << endl;
      return 0;
    }
    if(i%3 == 0) t = "b" + t + "b";
    if(i%3 == 1) t = "a" + t + "c";
    if(i%3 == 2) t = "c" + t + "a";
  }

  return 0;
}
