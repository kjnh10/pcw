#include <bits/stdc++.h>
using namespace std;

main()
{
  int A, B;

  cin >> A >> B; A %= B;

  if(A == 0) A = B;

  cout << B - A << endl;

  return 0;
}
