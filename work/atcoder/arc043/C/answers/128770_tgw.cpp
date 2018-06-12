#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i <(n); ++i)
#define ALL(x) (x).begin(), (x).end()
typedef long double ld;
using namespace std;

int main (void) {
  int N;
  ld A, B;
  cin >> N >> A >> B;
  vector<ld> S(N);
  ld Sa = 0;
  REP (i, N) {
    cin >> S[i];
    Sa += S[i];
  }
  Sa /= N;
  sort(ALL(S));
  if (S[0] == S[N - 1])
    cout << -1 << endl;
  else {
    ld P = B / (S[N - 1] - S[0]);
    ld Q = A - P * Sa;
    cout << fixed << setprecision(20) << P << " " << Q << endl;
  }
  return 0;
}
