#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<
#define sz(x) ((int) x.size())

typedef long long ll;
typedef pair<int, int> point;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);


  int q; cin >> q;
  while(q --) {
    ll a, b; cin >> a >> b;

    if(a > b) swap(a, b);

    ll sol = a - 1;

    ll lo = 0, hi = b - 1;
    while(lo < hi) {
      ll mid = (lo + hi + 1) >> 1;

      ll lo1 = 0, hi1 = mid - 1;

      while(lo1 < hi1) {

        ll mid1 = (lo1 + hi1) >> 1;

        if((mid - mid1) * (a + 1 + mid1) > (mid - (mid1 + 1)) * (a + 2 + mid1)) {
          hi1 = mid1;
        }
        else {
          lo1 = mid1 + 1;
        }

      }

      if((mid - lo1) * (a + 1 + lo1) < a * b) {
        lo = mid;
      }

      else {
        hi = mid - 1;
      }

    }

    cout << sol + lo << endl;
  }
}
