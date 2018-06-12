#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<string>
#include<string.h>
#include<vector>
#include<set>
#include<map>
#include<stdlib.h>
using namespace std;
const long long mod=1000000007;
const long long inf=mod*mod;
long long dp[1100][1100];
long long inv[3333];
long long fact[3333];
long long finv[3333];
long long C(int a,int b){
	return fact[a]*finv[b]%mod*finv[a-b]%mod;
}
int main(){
	int n,a,b,c,d;
	scanf("%d%d%d%d%d",&n,&a,&b,&c,&d);
	inv[1]=fact[0]=finv[0]=1;
	for(int i=2;i<3333;i++){
		inv[i]=(mod-(mod/i)*inv[mod%i]%mod)%mod;
	}
	for(int i=1;i<3333;i++){
		fact[i]=fact[i-1]*i%mod;
		finv[i]=finv[i-1]*inv[i]%mod;
	}
	dp[1][0]=1;
	for(int i=1;i<=b;i++){
		for(int j=0;j<=n;j++){
			if(!dp[i][j])continue;
			dp[i+1][j]=(dp[i+1][j]+dp[i][j])%mod;
		//	printf("%d %d: %lld\n",i,j,dp[i][j]);
			if(i>=a){
				int rem=n-j;
				long long ks=1;
				for(int k=1;k<=d;k++){
					if(j+k*i>n)break;
					ks=ks*C(rem,i)%mod;
					rem-=i;
					if(k>=c)dp[i+1][j+k*i]=(dp[i+1][j+k*i]+dp[i][j]*ks%mod*finv[k])%mod;
				}
			}
		}
	}
	printf("%lld\n",dp[b+1][n]);
}