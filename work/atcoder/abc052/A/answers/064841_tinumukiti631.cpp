#include <bits/stdc++.h>
using namespace std;
#define Rep(i,N) for(int i = 0; i < N; i++)
int main()
{
  int A, B, C, D;
  cin >> A >> B >> C >> D;
  cout << max(A * B, C * D) << endl;
  return 0;
}