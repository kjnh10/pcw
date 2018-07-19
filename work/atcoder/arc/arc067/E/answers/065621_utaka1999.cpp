#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <cmath>
#include <string>
#include <set>
#include <map>
#include <functional>
#include <cassert>
#define SIZE 1005
#define MOD 1000000007

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

ll inv[SIZE],fac[SIZE],finv[SIZE];
ll dp[SIZE],way[SIZE];
ll nxt[SIZE];

void make()
{
	fac[0]=fac[1]=1;
	finv[0]=finv[1]=1;
	inv[1]=1;
	for(int i=2;i<SIZE;i++)
	{
		inv[i]=MOD-inv[MOD%i]*(MOD/i)%MOD;
		fac[i]=fac[i-1]*(ll) i%MOD;
		finv[i]=finv[i-1]*inv[i]%MOD;
	}
}
ll Cb(int a,int b)
{
	if(a<b) return 0;
	return fac[a]*(finv[b]*finv[a-b]%MOD)%MOD;
}

int main()
{
	make();
	int n,A,B,C,D;
	scanf("%d %d %d %d %d",&n,&A,&B,&C,&D);
	memset(dp,0,sizeof(dp));
	dp[0]=1;
	for(int i=A;i<=B;i++)
	{
		memset(nxt,0,sizeof(nxt));
		for(int j=0;j<=n;j++)
		{
			if(dp[j]==0) continue;
			ll way=1;
			for(int k=0;k<=n-j;k+=i)
			{
				if(k==0||(C<=k/i&&k/i<=D))
				{
					nxt[j+k]+=dp[j]*way%MOD;
					if(nxt[j+k]>=MOD) nxt[j+k]-=MOD;
				}
				if(n-j-k<i) break;
				way=way*Cb(n-j-k,i)%MOD*inv[k/i+1]%MOD;
			}
		}
		for(int j=0;j<=n;j++) dp[j]=nxt[j];
	}
	printf("%lld\n",dp[n]);
	return 0;
}
