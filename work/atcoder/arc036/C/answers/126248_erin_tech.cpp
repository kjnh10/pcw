#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<ll> VL;
typedef vector<VL> VVL;
typedef pair<int, int> PII;

#define FOR(i, a, n) for (ll i = (ll)a; i < (ll)n; ++i)
#define REP(i, n) FOR(i, 0, n)
#define ALL(x) x.begin(), x.end()
#define MOD 1000000007
#define INF (1LL<<25)     //33554432
#define PI 3.14159265359
#define EPS 1e-12
//#define int ll

signed main(void)
{
  int n, k, t[100010];
  cin >> n >> k;
  REP(i, n) cin >> t[i];

  int ret = t[0] + t[1], ans = INF;
  FOR(i, 2, n) {
    ret += t[i];
    if(ret < k) ans = min(ans, (int)i+1);
    ret -= t[i-2];
  }

  if(ans == INF) cout << -1 << endl;
  else cout << ans << endl;

  return 0;
}
