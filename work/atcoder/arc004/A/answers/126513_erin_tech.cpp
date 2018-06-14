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
  int n, x[105], y[105];
  cin >> n;
  REP(i, n) {
    cin >> x[i] >> y[i];
  }

  double ret = -INF;
  REP(i, n) FOR(j, i+1, n) {
    double d = (x[i] - x[j])*(x[i] - x[j]) + (y[i] - y[j])*(y[i] - y[j]);
    ret = max(ret, d);
  }

  cout << fixed << setprecision(9) << sqrt(ret) << endl;

  return 0;
}
