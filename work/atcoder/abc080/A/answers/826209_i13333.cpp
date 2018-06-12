#include<bits/stdc++.h>

using namespace std;

using int64 = long long;
const int INF = 1 << 30;

int main()
{
  int N, A, B;
  cin >> N >> A >> B;
  cout << min(B, A * N) << endl;

}