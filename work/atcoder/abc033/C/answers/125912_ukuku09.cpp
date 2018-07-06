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

  string s;
  cin >> s;
  replace(all(s), '+', ' ');
  stringstream ss(s);
  string t;
  int cnt = 0;
  while(ss >> t) {
    if(count(all(t), '0') == 0) cnt++;
  }
  cout << cnt << endl;

  return 0;
}
