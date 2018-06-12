#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <map>
#include <set>
#include <functional>
#include <stack>
#include <cmath>
#include <string>
#define MOD 1000000007

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

int dp[2][2][2][2];

int main()
{
	ll N;
	scanf("%lld",&N);
	int pos=0;
	memset(dp,0,sizeof(dp));
	dp[pos][0][0][0]=1;
	for(int i=0;i<100;i++)
	{
		pos^=1;
		memset(dp[pos],0,sizeof(dp[pos]));
		int d=(int) (N%2);
		N/=2;
		for(int j=0;j<2;j++)
		{
			for(int k=0;k<2;k++)
			{
				for(int r=0;r<2;r++)
				{
					for(int s=0;s<2;s++)
					{
						for(int t=0;t<2;t++)
						{
							if(s==1&&t==0) continue;
							int a=s^t;
							int b=r+s+t;
							int x=a>d?1:a<d?0:j;
							int y=(b%2)>d?1:(b%2)<d?0:k;
							int z=b/2;
							dp[pos][x][y][z]+=dp[pos^1][j][k][r];
							if(dp[pos][x][y][z]>=MOD) dp[pos][x][y][z]-=MOD;
						}
					}
				}
			}
		}
	}
	printf("%d\n",dp[pos][0][0][0]);
	return 0;
}
