#include <bits/stdc++.h>
using namespace std;
#define int long long
#define Rep(i, N) for(int i = 0; i < N; i++)

signed main()
{
  int A[3];

  Rep(i, 3) cin >> A[i];

  sort(A, A + 3);

  if(A[0] != A[1]) cout << A[0] << endl;
  else cout << A[2] << endl;
  return 0;
}
