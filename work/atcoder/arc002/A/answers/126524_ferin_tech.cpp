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
  int y;
  cin >> y;

  if(y%400 == 0) {
    cout << "YES" << endl;
    return 0;
  } if(y%4 == 0 && y%100 != 0) {
    cout << "YES" << endl;
    return 0;
  }

  cout << "NO" << endl;  
  return 0;
}
