#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

#define int long long
int N, A, B;
signed main() {
  cin >> N >> A >> B;
  int l = (1LL<<60), r = -(1LL<<60), s = 0;
  for (int i=0; i<N; i++) {
    int x;
    cin >> x;
    l = min(l, x);
    r = max(r, x);
    s += x;
  }
  if (l == r) {
    cout << -1 << "\n";
  }
  else {
    long double P = B / (double)(r-l);
    long double Q = A - (P*s) / (double)N;
    cout << fixed << setprecision(10) << P << " " << Q << "\n";
  }
  return 0;
}
