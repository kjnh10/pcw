#include<bits/stdc++.h>

using namespace std;


int main()
{
  int N;
  bitset< 100 * 101 > dp;
  dp[0] = 1;

  cin >> N;
  for(int i = 0; i < N; i++) {
    int K;
    cin >> K;
    dp |= dp << K;
  }

  int ret = 0;
  for(int i = 0; i < 100 * 101; i++) {
    if(i % 10 != 0 && dp[i]) ret = max(ret, i);
  }
  cout << ret << endl;
}