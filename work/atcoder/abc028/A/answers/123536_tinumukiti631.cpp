#include <bits/stdc++.h>
using namespace std;
#define int long long
#define Rep(i, N) for(int i = 0; i < N; i++)

signed main()
{
  int N;

  cin >> N;

  if(N == 100) {
    cout << "Perfect" << endl;
  } else if(N >= 90) {
    cout << "Great" << endl;
  } else if(N >= 60) {
    cout << "Good" << endl;
  } else {
    cout << "Bad" << endl;
  }

  return 0;
}
