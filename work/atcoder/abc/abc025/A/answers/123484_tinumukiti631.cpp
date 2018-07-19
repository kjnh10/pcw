#include <bits/stdc++.h>
using namespace std;
#define int long long
#define Rep(i, N) for(int i = 0; i < N; i++)

signed main()
{
  string S;
  int N;
  
  cin >> S >> N; --N;
  sort(S.begin(), S.end());
  
  cout << S[N / 5] << S[N % 5] << endl;
  return 0;
}

