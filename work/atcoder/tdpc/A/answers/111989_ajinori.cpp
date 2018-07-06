#include <bits/stdc++.h>
using namespace std;
int n;
int p[100];
int dp[100][10000];
bool cc[10000];
//i以降の数値の個数を求める
int rec(int i,int s){
	if(i==n){
		if(cc[s]==false){
			cc[s]=true;
			// printf("r1 : %d\n",s);
			return 1;
		}else {
			// printf("r0 : %d\n",s);
			return 0;
		}
	}
	if(dp[i][s]!=-1){
		// printf("i:%d s:%d dp:%d\n",i,s,dp[i][s]);
		return 0;
	}
	int res = rec(i+1,s+p[i])+rec(i+1,s);
	dp[i][s] = res;
	return res;
}
int main(){
	memset(cc,0,sizeof(cc));
	memset(dp,-1,sizeof(dp));
	scanf("%d",&n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&p[i]);
	}
	printf("%d\n",rec(0,0));
	return 0;
}