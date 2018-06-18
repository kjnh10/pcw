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
  int n;
  string s;
  cin >> n >> s;

  int sum = 0;
  REP(i, n) {
    if(s[i] == 'D') sum += 1;
    else if(s[i] == 'C') sum += 2;
    else if(s[i] == 'B') sum += 3;
    else if(s[i] == 'A') sum += 4;
  }

  cout << fixed << setprecision(18) << (double)sum/n << endl;

  return 0;
}
