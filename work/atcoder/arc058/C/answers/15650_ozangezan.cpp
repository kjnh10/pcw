#include<stdio.h>
#include<algorithm>
using namespace std;
long long mod=1000000007;
long long dp[42][1<<17];
int to[1<<17][10];
int main(){
	int a,b,c,d;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	long long sub=1;
	for(int i=0;i<a;i++)sub=sub*10%mod;
	dp[0][1]=1;
	for(int i=0;i<(1<<(b+c+d));i++){
		for(int j=0;j<10;j++){
			int tmp=1;
			bool dame=false;
			for(int k=0;k<b+c+d;k++){
				if(!((1<<k)&i))continue;
				if(k<b&&k+j+1>b)continue;
				if(k<b+c&&k+j+1>b+c)continue;
				if(k<b+c+d&&k+j+1>b+c+d)continue;
				if(k+j+1==b+c+d){dame=true;break;}
				tmp+=1<<(k+j+1);
			}
			if(dame)tmp=-1;
			to[i][j]=tmp;
		}
	}
	for(int i=0;i<a;i++){
		for(int j=0;j<(1<<(b+c+d));j++){
			if(!dp[i][j])continue;
		//	printf("%d %d: %lld\n",);
			for(int k=0;k<10;k++){
				if(to[j][k]==-1)continue;
				dp[i+1][to[j][k]]=(dp[i+1][to[j][k]]+dp[i][j])%mod;
			}
		}
	}
	long long ret=0;
	for(int i=0;i<(1<<(b+c+d));i++)ret=(ret+dp[a][i])%mod;
	printf("%lld\n",(mod+sub-ret)%mod);
}