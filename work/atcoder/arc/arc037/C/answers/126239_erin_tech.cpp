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
  int n, m[30];
  cin >> n;
  REP(i, n) cin >> m[i];

  int ret = 0;
  REP(i, n) {
    if(m[i] < 80) {
      ret += 80-m[i];
    }
  }

  cout << ret << endl;

  return 0;
}
