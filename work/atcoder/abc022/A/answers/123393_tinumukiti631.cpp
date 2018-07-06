#include <bits/stdc++.h>
using namespace std;
#define int long long
#define Rep(i, N) for(int i = 0; i < N; i++)

signed main()
{
  int N, S, T, cnt = 0;
  int A;
  int sum = 0;

  cin >> N >> S >> T;
  
  Rep(i, N) {
    cin >> A; sum += A;
    if(S <= sum && sum <= T) cnt++;
  }

  cout << cnt << endl;

  return 0;
}
