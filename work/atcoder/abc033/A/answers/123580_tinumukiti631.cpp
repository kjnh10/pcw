#include <bits/stdc++.h>
using namespace std;
#define int long long
#define Rep(i, N) for(int i = 0; i < N; i++)

signed main()
{
  string S;
  cin >> S;
  if(S[0] == S[1] && S[0] == S[2] && S[0] == S[3]) cout << "SAME" << endl;
  else cout << "DIFFERENT" << endl;

  return 0;
}
