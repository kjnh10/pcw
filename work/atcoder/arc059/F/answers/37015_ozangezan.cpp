#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
char in[5100];
long long mod=1000000007;
long long d2=500000004;
long long dp[2][5010];
int main(){
	int a;scanf("%d",&a);
	scanf("%s",in);
	int n=strlen(in);
	long long ret=0;
	dp[0][0]=1;
	for(int i=0;i<a;i++){
		int t=i%2;
		for(int j=0;j<5010;j++)dp[!t][j]=0;
		for(int j=0;j<5010;j++){
			if(!dp[t][j])continue;
	//		printf("%d %d: %lld\n",i,j,dp[t][j]);
			dp[!t][max(0,j-1)]=(dp[!t][max(0,j-1)]+dp[t][j])%mod;
			dp[!t][j+1]=(dp[!t][j+1]+dp[t][j]*2)%mod;
		}
	}
	ret=dp[a%2][n];
	for(int i=0;i<n;i++)ret=ret*d2%mod;
	printf("%lld\n",ret);
}