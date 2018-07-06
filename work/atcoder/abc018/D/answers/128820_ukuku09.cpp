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

  int N, M, P, Q, R;
  cin >> N >> M >> P >> Q >> R;
  vector< pair<int, int> > choco[18];
  rep(i, R) {
    int x, y, z;
    cin >> x >> y >> z;
    --x, --y;
    choco[x].emplace_back(y, z);
  }
  int ans = 0;
  for(int bit = (1<<P)-1; bit < 1<<N; bit++) {
    if(__builtin_popcount(bit) != P) continue;
    vector<int> happy(M, 0);
    for(int i = 0; i < N; i++) {
      if(!((bit>>i)&1)) continue;
      for(auto p : choco[i]) happy[p.first] += p.second;
    }
    sort(all(happy));
    reverse(all(happy));
    int sum = 0;
    for(int i = 0; i < Q; i++) sum += happy[i];
    ans = max(ans, sum);
  }
  cout << ans << endl;

  return 0;
}
