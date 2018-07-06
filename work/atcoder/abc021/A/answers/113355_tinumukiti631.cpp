#include <bits/stdc++.h>
using namespace std;
#define Rep(i, N) for(int i = 0; i < N; i++)

signed main()
{
  int N, cnt = 0;
  vector< int > out;
  
  cin >> N;
  
  Rep(i, 4) {
    if((N >> i) & 1) {
      out.push_back(1 << i);
      cnt++;
    }
  }

  cout << cnt << endl;
  Rep(i, out.size()) {
    cout << out[i] << endl;
  }

  return 0;
}
