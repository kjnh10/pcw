#include <bits/stdc++.h>
using namespace std;
#define int long long
#define Rep(i, N) for(int i = 0; i < N; i++)
#define Reps(i, x, N) for(int i = x; i < N; i++)

inline int llabs(int n) { return n < 0 ? -n : n; }

signed main()
{
  int N, A, sum = 0, cnt = 0;

  cin >> N;

  Rep(i, N) {
    cin >> A; sum += A;
    if(A) cnt++;
  }

  if(sum % cnt) cout << sum / cnt + 1 << endl;
  else cout << sum / cnt << endl;

  return 0;
}
