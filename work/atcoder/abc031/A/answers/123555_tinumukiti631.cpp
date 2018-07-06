#include <bits/stdc++.h>
using namespace std;
#define int long long
#define Rep(i, N) for(int i = 0; i < N; i++)

signed main()
{
  int A, B;
  cin >> A >> B;

  if(A > B) B++;
  else A++;

  cout << A * B << endl;

  return 0;
}
