#include <bits/stdc++.h>
using namespace std;
#define int long long
#define Rep(i, N) for(int i = 0; i < N; i++)

signed main()
{
  int A, B, C, K;
  int S, T;

  cin >> A >> B >> C >> K >> S >> T;

  if(S + T >= K) cout << A * S + B * T - C * (S + T) << endl;
  else cout << A * S + B * T << endl;

  return 0;
}