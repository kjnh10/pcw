#include <stdio.h>

#define PE(a, b) ((a)+=(b), ((a)>=mod) ? (a)-=mod : 0)

const int mod = 1000000007;

int dic[8][256];
int dp[2][128][256];
int trans[128][256][2];

int main(){
  int n, l;
  int i, j, k;
  int ans;
  scanf("%d%d", &n, &l);
  for(i=0;i<n;i++){
    char x = 0;
    int s, len;
    while(x != '0' && x != '1') x = getchar_unlocked();
    for(s=len=0;x>='0';len++){
      s <<= 1;
      s |= x - '0';
      x = getchar_unlocked();
    }
    dic[len-1][s]++;
  }

  for(j=0;j<128;j++){
    for(k=0;k<256;k++){
      int f0, f1, u;
      f0 = f1 = 0;
      for(u=k;u;){
        int t = __builtin_ctz(u);
        if(dic[t][((j<<1)|0)&((1<<(t+1))-1)]) f0=1;
        if(dic[t][((j<<1)|1)&((1<<(t+1))-1)]) f1=1;
        u^=1<<t;
      }
      trans[j][k][0] = f0;
      trans[j][k][1] = f1;
    }
  }

  dp[0][0][1] = 1;

  for(i=0;i<l;i++){
    int b = i&1;
    for(j=0;j<128;j++){
      for(k=0;k<256;k++){
        int a;
        a = dp[b][j][k];
        if(!a) continue;

        if(trans[j][k][0]) PE(dp[b^1][127&((j<<1)|0)][255&((k<<1)|1)], a);
        else   PE(dp[b^1][127&((j<<1)|0)][255&((k<<1)|0)], a);
        if(trans[j][k][1]) PE(dp[b^1][127&((j<<1)|1)][255&((k<<1)|1)], a);
        else   PE(dp[b^1][127&((j<<1)|1)][255&((k<<1)|0)], a);
        dp[b][j][k]=0;
      }
    }
  }

  ans = 0;
  for(j=0;j<128;j++){
    for(k=1;k<256;k+=2){
      PE(ans, dp[l&1][j][k]);
    }
  }
  printf("%d\n", ans);

  return 0;
}
