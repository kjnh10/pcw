#include<bits/stdc++.h>
using namespace std;
typedef long long int64;

int N, M;
int x[16];
int64 dp[1 << 16];

int64 rec(int bit)
{
  if(~dp[bit]) return(dp[bit]);
  if((1 << N) - 1 == bit) return(1);
  int64 ret = 0;
  for(int i = 0; i < N; i++) {
    if(bit & x[i]) continue;
    if((bit >> i) & 1) continue;
    ret += rec(bit | (1 << i));
  }
  return(dp[bit] = ret);
}
int main()
{
  memset(dp, -1, sizeof(dp));
  cin >> N;
  cin >> M;
  for(int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    x[a] |= (1 << b);
  }
  cout << rec(0) << endl;
}
