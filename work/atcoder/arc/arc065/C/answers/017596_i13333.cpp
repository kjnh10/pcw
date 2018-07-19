#include <bits/stdc++.h>

using namespace std;


int main()
{
  string S;
  bool dp[100001] = {};

  string K[4] = {
      "dream", "dreamer", "erase", "eraser"
  };

  cin >> S;
  dp[0] = true;
  for(int i = 0; i < S.size(); i++) {
    if(dp[i]) {
      for(int j = 0; j < 4; j++) {
        dp[i + K[j].size()] |= S.substr(i, K[j].size()) == K[j];
      }
    }
  }

  cout << (dp[S.size()] ? "YES" : "NO") << endl;
}