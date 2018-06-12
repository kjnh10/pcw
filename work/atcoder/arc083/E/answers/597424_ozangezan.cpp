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
#include<stdlib.h>
#include<cassert>
using namespace std;
const long long mod=1000000009;
const long long inf=mod*mod;
const long long d2=500000004;
const double EPS=1e-6;
const double PI=acos(-1.0);
int ABS(int a){return max(a,-a);}
long long ABS(long long a){return max(a,-a);}
vector<int>g[1100];
int c[1100];
int dp2[1100];
bool ok=true;
int dp[1100][5100];
void solve(int a){
	for(int i=0;i<g[a].size();i++){
		solve(g[a][i]);
	}
	if(!ok)return;
	int n=g[a].size();
	for(int i=0;i<=n;i++)for(int j=0;j<5100;j++)dp[i][j]=mod;
	dp[0][0]=0;
	for(int i=0;i<n;i++){
		int A=c[g[a][i]];
		int B=dp2[g[a][i]];
		for(int j=0;j<5100;j++){
			if(dp[i][j]<mod){
				if(j+A<5100)dp[i+1][j+A]=min(dp[i+1][j+A],dp[i][j]+B);
				if(j+B<5100)dp[i+1][j+B]=min(dp[i+1][j+B],dp[i][j]+A);
			}
		}
	}
	int rm=mod;
	for(int i=0;i<=c[a];i++){
		rm=min(rm,dp[n][i]);
	}
	if(rm==mod)ok=false;
	dp2[a]=rm;
	//printf("%d: %d\n",a,dp2[a]);
}
int main(){
	int a;scanf("%d",&a);
	for(int i=1;i<a;i++){
		int b;
		scanf("%d",&b);
		b--;g[b].push_back(i);
	}
	for(int i=0;i<a;i++)scanf("%d",c+i);
	solve(0);
	if(ok)printf("POSSIBLE\n");
	else printf("IMPOSSIBLE\n");
}