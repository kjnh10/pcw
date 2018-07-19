#include <bits/stdc++.h>
using namespace std;
#define int long long
#define Rep(i, N) for(int i = 0; i < N; i++)
#define Reps(i, x, N) for(int i = x; i < N; i++)

inline int llabs(int n) { return n < 0 ? -n : n; }

signed main()
{
  string S;

  cin >> S;

  int i = 0;
  while(i < S.size()) {
    if(i < S.size() - 1 && S[i] == 'c' && S[i + 1] == 'h') i += 2;
    else if(S[i] == 'o') i++;
    else if(S[i] == 'k') i++;
    else if(S[i] == 'u') i++;
    else break;
  }

  if(i == S.size()) cout << "YES" << endl;
  else cout << "NO" << endl;

  return 0;
}
    
