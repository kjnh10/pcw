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
  int a, b, n, x[13], y[13];
  cin >> a >> b >> n;
  REP(i, n) cin >> x[i] >> y[i];

  double ans = INF;
  FOR(i, 1, n) {
    int p = x[i] - x[i-1], q = y[i] - y[i-1];
    double d = abs(p*b-q*a+q*x[i-1]-p*y[i-1])/sqrt(p*p+q*q);
    //cout << p << " " << " " << q << " " << d << endl;
    ans = min(ans, d);
  }
  int p = x[0] - x[n-1], q = y[0] - y[n-1];
  double d = abs(p*b-q*a+q*x[n-1]-p*y[n-1])/sqrt(p*p+q*q);
  ans = min(ans, d);
  ///cout << p << " " << " " << q << " " << d << endl;

  cout << fixed << setprecision(15) << ans << endl;

  return 0;
}
