#include <cstdio>
#include <cstring>
#include <vector>

const int mod = 1000000007;

typedef long long int ll;

std::vector<int> g[1000];
std::vector<int> u[1000];

int dp[2000][3][51];


int solve(int i, int j, int k, int l, int p){
  if(j==0) return k==0&&l==0;
  if(dp[u[i][j-1]][k][l]>=0) return dp[u[i][j-1]][k][l];
  int ii = g[i][j-1];
  if(ii == p) return dp[u[i][j-1]][k][l] = solve(i, j-1, k, l, p);
  int ans = 0;
  if(k==0){
    for(int t = 0; t <= l; t++){
      ans = (ans + ((ll) solve(ii, g[ii].size(), 0, t, i) + solve(ii, g[ii].size(), 1, t, i) + solve(ii, g[ii].size(), 2, t, i)) * solve(i, j-1, 0, l-t, p)) % mod;
    }
  }
  else if(k==1){
    for(int t = 0; t <= l; t++){
      ans = (ans + ((ll) solve(ii, g[ii].size(), 0, t, i) + solve(ii, g[ii].size(), 1, t, i) + solve(ii, g[ii].size(), 2, t, i)) * solve(i, j-1, 1, l-t, p)
                 + (ll) solve(ii, g[ii].size(), 1, t, i) * solve(i, j-1, 0, l-t, p)
                 + ((t == l) ? 0 : (ll) solve(ii, g[ii].size(), 0, t, i) * solve(i, j-1, 0, l-t-1, p))) % mod;
    }
  }
  else if(k==2){
    for(int t = 0; t <= l; t++){
      ans = (ans + ((ll) solve(ii, g[ii].size(), 0, t, i) + solve(ii, g[ii].size(), 1, t, i) + solve(ii, g[ii].size(), 2, t, i)) * solve(i, j-1, 2, l-t, p)
                 + (ll) solve(ii, g[ii].size(), 0, t, i) * solve(i, j-1, 1, l-t, p)
                 + ((t == 0) ? 0 : (ll) solve(ii, g[ii].size(), 1, t, i) * solve(i, j-1, 1, l-t+1, p))) % mod;
    }
  }

// printf("SOLVE  %d %d %d %d %d = %d\n", i,j,k,l,p, ans);
  return dp[u[i][j-1]][k][l] = ans;
}


int main(){
  int n, k, ans;
  scanf("%d%d", &n, &k);
  for(int i=0; i<n-1; i++){
    int a, b;
    scanf("%d%d", &a, &b);
    g[a-1].push_back(b-1);
    g[b-1].push_back(a-1);
    u[a-1].push_back(2*i);
    u[b-1].push_back(2*i+1);
  }

  memset(dp, -1, sizeof(dp));

  ans = ((ll) solve(0, g[0].size(), 0, k, -1)
         +    solve(0, g[0].size(), 1, k, -1)
         +    solve(0, g[0].size(), 2, k, -1)) % mod;

  printf("%d\n", ans);

  return 0;
}
