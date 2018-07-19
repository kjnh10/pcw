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

  int a[3];
  REP(i, 3) {
    cin >> a[i];
  }
  sort(a, a + 3);

  if((2 * a[2] - a[1] - a[0]) % 2) {
    cout << (2 * a[2] - a[1] - a[0]) / 2 + 2;
  }
  else {
    cout << (2 * a[2] - a[1] - a[0]) / 2;
  }
}
