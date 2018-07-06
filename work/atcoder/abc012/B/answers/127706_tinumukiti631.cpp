#include <bits/stdc++.h>
using namespace std;
#define int long long
#define Rep(i, N) for(int i = 0; i < N; i++)
#define Reps(i, x, N) for(int i = x; i < N; i++)

signed main()
{
  int N;
  cin >> N;

  if(N / 3600 < 10) cout << 0;
  cout << N / 3600 << ":";
  if((N / 60) % 60 < 10) cout << 0;
  cout << (N / 60) % 60 << ":";
  if(N % 60 < 10) cout << 0;
  cout << N % 60 << endl;

  return 0;
}
