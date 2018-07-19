#include <bits/stdc++.h>
using namespace std;
#define int long long
#define Rep(i, N) for(int i = 0; i < N; i++)
#define Reps(i, x, N) for(int i = x; i < N; i++)

signed main()
{
  string S;
  cin >> S;

  if(islower(S[0])) S[0] -= 'a' - 'A';
  Reps(i, 1, S.size()) {
    if(isupper(S[i])) S[i] += 'a' - 'A';
  }

  cout << S << endl;

  return 0;
}
