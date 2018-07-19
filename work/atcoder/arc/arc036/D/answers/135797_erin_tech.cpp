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

int h[300010];
signed main(void)
{
  int n;
  cin >> n;
  REP(i, n) cin >> h[i];

  int ret = 1, maxret = -INF;
  bool israise = true;
  FOR(i, 1, n) {
    if(israise) {
      if(h[i] > h[i-1]) {
        ret++;
      } else {
        israise = false;
        ret++;
      }
    } else {
      if(h[i] < h[i-1]) {
        ret++;
      } else {
        israise = true;
        maxret = max(maxret, ret);
        ret = 2;
      }
    }
    //cout << i << " " << ret << endl;
  }
  maxret = max(maxret, ret);

  cout << maxret << endl;
  return 0;
}
