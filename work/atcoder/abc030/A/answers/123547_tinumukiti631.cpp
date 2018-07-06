#include <bits/stdc++.h>
using namespace std;
#define int long long
#define Rep(i, N) for(int i = 0; i < N; i++)

inline int lcm(int a, int b) { return a / __gcd(a, b) * b; }

signed main()
{
  int A, B, C, D;

  cin >> A >> B >> C >> D;

  int l = lcm(A, C);

  if(l / A * B > l / C * D) {
    cout << "TAKAHASHI" << endl;
  } else if(l / A * B == l / C * D) {
    cout << "DRAW" << endl;
  } else {
    cout << "AOKI" << endl;
  }

  return 0;
}