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
  int n, a[1010];
  cin >> n;
  REP(i, n) cin >> a[i];
  sort(a, a+n);

  int ret = 0;
  for(int i=n-1; i>=0; i -= 2) {
    //cout << a[i] << " ";
    ret += a[i];
  }
  //cout << endl;

  cout << ret << endl;

  return 0;
}
