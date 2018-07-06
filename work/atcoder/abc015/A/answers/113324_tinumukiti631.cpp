#include <bits/stdc++.h>
using namespace std;

main()
{
  string S, T;

  cin >> S >> T;

  if(S.size() > T.size()) {
    cout << S << endl;
  } else {
    cout << T << endl;
  }

  return 0;
}
