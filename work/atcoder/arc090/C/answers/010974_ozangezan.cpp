#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<deque>
#include<string>
#include<string.h>
#include<vector>
#include<set>
#include<map>
#include<bitset>
#include<stdlib.h>
#include<cassert>
#include<time.h>
#include<bitset>
using namespace std;
const long long mod=1000000007;
const long long inf=mod*mod;
const long long d2=(mod+1)/2;
const double EPS=1e-6;
const double PI=acos(-1.0);
int ABS(int a){return max(a,-a);}
long long ABS(long long a){return max(a,-a);}
int p[3][110];
int dp[3][110];
int main(){
	int a;scanf("%d",&a);
	for(int i=0;i<2;i++)for(int j=0;j<a;j++)scanf("%d",&p[i][j]);
	dp[0][0]=p[0][0];
	for(int i=0;i<2;i++)for(int j=0;j<a;j++){
		if(i==0)dp[i+1][j]=max(dp[i+1][j],dp[i][j]+p[i+1][j]);
		if(j<a-1)dp[i][j+1]=max(dp[i][j+1],dp[i][j]+p[i][j+1]);
	}
	printf("%d\n",dp[1][a-1]);
}
