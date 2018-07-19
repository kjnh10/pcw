#include <bits/stdc++.h>
using namespace std;

signed main()
{
  int A, B, sum = 0;

  for(int i = 0; i < 3; i++) {
    cin >> A >> B; A /= 10;

    sum += A * B;
  }

  cout << sum << endl;


  return 0;
}
