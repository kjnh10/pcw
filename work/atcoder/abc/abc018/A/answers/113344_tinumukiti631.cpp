#include <bits/stdc++.h>
using namespace std;
#define Rep(i, N) for(int i = 0; i < N; i++)
 
signed main()
{
  int pos[105], A, out[3], cnt = 1;

  fill_n(pos, 105, -1);
  
  Rep(i, 3) {
    cin >> A; pos[A] = i;
  }

  for(int i = 100; i > 0; i--) {
    if(~pos[i]) {
      out[pos[i]] = cnt;
      cnt++;
    }
  }

  Rep(i, 3) {
    cout << out[i] << endl;
  }

  return 0;
}
  
    