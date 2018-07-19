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
#define INF (1LL << 25) // 33554432
#define PI 3.14159265359
#define EPS 1e-12
//#define int ll

int c[100010][5], r[100010], h[100010];
signed main(void) {
  int n, mr = -1;
  cin >> n;
  REP(i, n) {
    cin >> r[i] >> h[i];
    mr = max(mr, r[i]);
    c[r[i]][h[i]]++;
  }

  FOR(i, 1, mr + 1) { c[i][0] = c[i - 1][0] + c[i][1] + c[i][2] + c[i][3]; }

  REP(i, n) {
    if (h[i] == 1)
      cout << c[r[i] - 1][0] + c[r[i]][2] << " "
           << c[mr][0] - c[r[i]][0] + c[r[i]][3] << " " << c[r[i]][1]-1 << endl;
    else if (h[i] == 2)
      cout << c[r[i] - 1][0] + c[r[i]][3] << " "
           << c[mr][0] - c[r[i]][0] + c[r[i]][1] << " " << c[r[i]][2]-1 << endl;
    else if (h[i] == 3)
      cout << c[r[i] - 1][0] + c[r[i]][1] << " "
           << c[mr][0] - c[r[i]][0] + c[r[i]][2] << " " << c[r[i]][3]-1 << endl;
  }

  return 0;
}
