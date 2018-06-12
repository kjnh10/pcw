#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
  int n;
  long long K;
  scanf("%d%lld",&n,&K);
  int a[2000];
  for(int i=0;i<n;i++){
    scanf("%d",a+i);
  }
  long long A[2000];
  A[0]=0;
  for(int i=0;i<n;i++){
    A[i+1]=A[i]+a[i];
  }
  static long long dp[2001][2001];
  for(int i=0;i<=n;i++){
    for(int j=0;j<=n;j++){
      dp[i][j]=K+1;
    }
  }
  dp[0][0]=0;
  for(int i=0;i<n;i++){
    for(int j=0;j<=i;j++){
      if(dp[i][j]==K+1){
	continue;
      }
      dp[i+1][j]=min(dp[i+1][j],dp[i][j]);
      dp[i+1][j+1]=min(dp[i+1][j+1],dp[i][j]+(A[i]==0?1:(dp[i][j]*a[i]+A[i])/A[i]));
    }
  }
  static long long dp2[2001][2001];
  for(int i=0;i<=n;i++){
    for(int j=0;j<=n;j++){
      dp2[i][j]=-1;
    }
  }
  dp2[0][0]=0;
  for(int i=0;i<n;i++){
    for(int j=0;j<=i;j++){
      if(dp2[i][j]==-1){
	continue;
      }
      //printf("%d %d %d\n",i,j,dp2[i][j]);
      dp2[i+1][j]=max(dp2[i+1][j],dp2[i][j]+(A[i]==0?0:dp2[i][j]*a[i]/A[i]));
      if(A[i]==0||dp2[i][j]<A[i]){
	dp2[i+1][j+1]=max(dp2[i+1][j+1],dp2[i][j]+a[i]);
      }
      else{
	dp2[i+1][j+1]=max(dp2[i+1][j+1],dp2[i][j]-1+a[i]);
      }
    }
  }
  int ans=-1;
  for(int j=0;j<=n;j++){
    //printf("%d %d\n",dp[n][j],dp2[n][j]);
    if(dp[n][j]<=K&&dp2[n][j]>=K){
      ans=j;
    }
  }
  printf("%d\n",ans);
  return 0;
}
