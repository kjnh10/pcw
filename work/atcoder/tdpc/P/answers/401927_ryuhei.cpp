#include <cstdio>
#include <vector>

const int mod = 1000000007;

typedef long long int ll;

int n, k;
std::vector<int> g[1000];

int dp[1000][3][52];
int tmp[2][3][52];

void solve(int i, int p){
  int b = 0;

  for(int x: g[i]){
    if(x != p) solve(x, i);
  }

  tmp[0][0][0] = 1;
  for(int x: g[i]){
    if(x == p) continue;
    for(int t = 0; t <= k; t++){
      for(int s = t; s <= k; s++){
        tmp[b^1][2][s] = (tmp[b^1][2][s] + tmp[b][2][t] * ((ll) dp[x][0][s-t] + dp[x][1][s-t] + dp[x][2][s-t])) % mod;
        tmp[b^1][2][s] = (tmp[b^1][2][s] + tmp[b][1][t] * ((ll) dp[x][0][s-t])) % mod;
        tmp[b^1][2][s] = (tmp[b^1][2][s] + tmp[b][1][t] * ((ll) dp[x][1][s-t+1])) % mod;
        tmp[b^1][1][s] = (tmp[b^1][1][s] + tmp[b][1][t] * ((ll) dp[x][0][s-t] + dp[x][1][s-t] + dp[x][2][s-t])) % mod;
        tmp[b^1][1][s] = (tmp[b^1][1][s] + tmp[b][0][t] * ((ll) dp[x][1][s-t])) % mod;
        if(t!=s) tmp[b^1][1][s] = (tmp[b^1][1][s] + tmp[b][0][t] * ((ll) dp[x][0][s-t-1])) % mod;
        tmp[b^1][0][s] = (tmp[b^1][0][s] + tmp[b][0][t] * ((ll) dp[x][0][s-t] + dp[x][1][s-t] + dp[x][2][s-t])) % mod;
      }
      tmp[b][0][t] = tmp[b][1][t] = tmp[b][2][t] = 0;
    }
    b ^= 1;
  }
  for(int s = 0; s <= k; s++){
    dp[i][0][s] = tmp[b][0][s];
    dp[i][1][s] = tmp[b][1][s];
    dp[i][2][s] = tmp[b][2][s];
    tmp[b][0][s] = tmp[b][1][s] = tmp[b][2][s] = 0;
  }
}


int main(){
  int ans;
  scanf("%d%d", &n, &k);
  for(int i=0; i<n-1; i++){
    int a, b;
    scanf("%d%d", &a, &b);
    g[a-1].push_back(b-1);
    g[b-1].push_back(a-1);
  }

  solve(0, -1);

  ans = ((ll) dp[0][0][k] + dp[0][1][k] + dp[0][2][k]) % mod;

  printf("%d\n", ans);

  return 0;
}
