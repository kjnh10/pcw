#include<bits/stdc++.h>

using namespace std;

using int64 = long long;
const int INF = 1 << 30;

int main()
{
  int64 N, C[500], S[500], F[500];

  cin >> N;
  for(int i = 0; i < N - 1; i++) {
    cin >> C[i] >> S[i] >> F[i];
  }

  for(int i = 0; i < N - 1; i++) {
    int64 t = 0;
    for(int j = i; j < N - 1; j++) {
      t = max(t, S[j]);
      t = S[j] + C[j] + (t - S[j] + F[j] - 1) / F[j] * F[j];
    }
    cout << t << endl;
  }
  cout << 0 << endl;


}