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
  /*int a, b;
  cin >> a >> b;

  int c = a%100 + 900 - b, d = a-b%100-100, e = a - b, ans = max(c, d);
  cout << max(ans, e) << endl;*/
  string a, b;
  cin >> a >> b;

  int minret = -INF;
  REP(i, 3) {
    for(char j='0'; j<='9'; ++j) {
      string c = a;
      if(i == 0 && j == '0') continue;
      c[i] = j;
      int ret = stoi(c) - stoi(b);
      minret = max(minret, ret);
    }
  }

  REP(i, 3) {
    for(char j='0'; j<='9'; ++j) {
      string c = b;
      if(i == 0 && j == '0') continue;
      c[i] = j;
      int ret = stoi(a) - stoi(c);
      minret = max(minret, ret);
    }
  }

  cout << minret << endl;

  return 0;
}
