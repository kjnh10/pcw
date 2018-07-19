#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

#define MOD 1000000007

int N;
int D[100000];
int dp[100001][4];
int S[4];

int f() {
  int s = 0, l = -1;
  for (int i=0; i<N; i++) {
    dp[i][3] = 1;
    while (l+1<i && D[l+1]>=D[i]*2) {
      l++;
      for (int j=0; j<4; j++) S[j] = (S[j] + dp[l][j]) % MOD;
    }
    for (int j=0; j<3; j++) dp[i][j] = S[j+1];
    s += dp[i][0];
    s %= MOD;
  }
  return s;
}

int main() {
  cin >> N;
  for (int i=0; i<N; i++) cin >> D[i];
  sort(D, D+N, greater<int>());
  cout << f() << "\n";
  return 0;
}
