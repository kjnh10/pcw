#include <bits/stdc++.h>
using namespace std;
#define int long long
#define Rep(i, N) for(int i = 0; i < N; i++)

signed main()
{
  int N;
  cin >> N; N++;
  cout << (N - 1) % 12 + 1 << endl;

  return 0;
}
