#include <bits/stdc++.h>
using namespace std;
//動的計画法
int SA,SB;
int a[1010],b[1010];
int dp[1010][1010];
int main(){
	scanf("%d %d",&SA,&SB);
	long long sum=0;
	for (int i = 0; i < SA; ++i)
	{
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	for (int i = 0; i < SB; ++i)
	{
		scanf("%d",&b[i]);
		sum+=b[i];
	}
	//ta:A山の残数,tb:B山の残数,返すのはスコア
	for (int ta = 0; ta <= SA; ++ta)
	{
		for (int tb = 0; tb <= SB; ++tb)
		{
			int turn = ((SA+SB-ta-tb)%2)*-2+1;
			if(ta==0&&tb==0){
				dp[0][0]=0;
			}else
			if(ta==0){
				dp[ta][tb]=dp[ta][tb-1]+b[SB-tb]*turn;
			}else
			if(tb==0){
				dp[ta][tb]=dp[ta-1][tb]+a[SA-ta]*turn;
			}else
			if(turn==1){
				dp[ta][tb]=max(dp[ta-1][tb]+a[SA-ta],dp[ta][tb-1]+b[SB-tb]);
			}else{
				dp[ta][tb]=min(dp[ta-1][tb]-a[SA-ta],dp[ta][tb-1]-b[SB-tb]);
			}
		}
	}
	printf("%lld\n",(dp[SA][SB]+sum)/2);
	return 0;
}