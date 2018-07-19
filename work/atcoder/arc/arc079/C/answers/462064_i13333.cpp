#include <bits/stdc++.h>

using namespace std;

int main()
{
  int N, M;
  cin >> N >> M;
  int latte[200000] = {}, malta[200000] = {};
  for(int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    if(a == 0) latte[b] = true;
    if(b == N - 1) malta[a] = true;
  }
  for(int i = 0; i < N; i++) {
    if(latte[i] && malta[i]) {
      cout << "POSSIBLE" << endl;
      return (0);
    }
  }
  cout << "IMPOSSIBLE" << endl;
}