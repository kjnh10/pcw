#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
const int64 LINF = 1LL << 61;
const int INF = 1 << 30;

int main()
{
  int N, D[100];
  cin >> N;
  set< int > s;
  for(int i = 0; i < N; i++) {
    int x;
    cin >> x;
    s.emplace(x);
  }

  cout << s.size() << endl;
}