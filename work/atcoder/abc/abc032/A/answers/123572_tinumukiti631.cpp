#include <bits/stdc++.h>
using namespace std;
#define int long long
#define Rep(i, N) for(int i = 0; i < N; i++)

inline int lcm(int a, int b) { return a / __gcd(a, b) * b; }

signed main()
{
  int A, B, N;
  
  cin >> A >> B >> N;

  A = lcm(A, B);
  
  cout << A + max(0LL, A * ((N - 1) / A))  << endl;

  return 0;
}
