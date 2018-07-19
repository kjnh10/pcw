#include <bits/stdc++.h>

using namespace std;

int main()
{
  int N, M;
  int G[50] = {};

  cin >> N >> M;
  for(int i = 0; i < M; i++) {
    int A, B;
    cin >> A >> B;
    --A, --B;
    G[A]++;
    G[B]++;
  }
  for(int i = 0; i < N; i++) {
    cout << G[i] << endl;
  }

}