#include <bits/stdc++.h>
using namespace std;
int n;
int p[100];
bool dp[100][10000];
bool cc[10000];
int main(){
	long long ans = 0;
	memset(cc,0,sizeof(cc));
	memset(dp,0,sizeof(dp));
	scanf("%d",&n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&p[i]);
	}
	dp[0][0]=true;
	dp[0][p[0]]=true;
	for (int i = 0; i < n-1; ++i)
	{
		for (int w = 0; w < 10000; ++w)
		{
			if(dp[i][w]==true){
				dp[i+1][w]=true;
				dp[i+1][w+p[i+1]]=true;
			}
		}
	}
	for (int w = 0; w < 10000; ++w)
	{
		if(dp[n-1][w]==true){
			ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}