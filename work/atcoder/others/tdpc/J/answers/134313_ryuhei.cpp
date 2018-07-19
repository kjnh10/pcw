#include <cstdio>

const int nmax = 16;

struct Table {
  constexpr Table() : dp() {
    dp[0] = 0.0;
    for(int x = 1; x < (1<<nmax); ++x) {
      if(x&1) {
        switch(x & 7){
          case 1: dp[x] = 3 +  dp[x>>1]; break;
          case 3: dp[x] = 3 + (dp[x>>1] + dp[x>>3])/2; break;
          case 5: dp[x] = 3 + (dp[x>>2] + dp[x>>3])/2; break;
          case 7: dp[x] = 3 + (2*dp[x>>1] + dp[x>>2] + dp[(x>>1)&~2] + 2*dp[x>>3])/6;
        }
      }
      else dp[x] = dp[x>>1];
    }
  }
  double dp[1<<nmax];
};

int main() {
  constexpr auto a = Table();
  int n, i, x;
  scanf("%d", &n);
  for(i=0;i<n;i++){
    int xi;
    scanf("%d", &xi);
    x |= 1 << xi;
  }

  printf("%.9g\n", a.dp[x]);
}