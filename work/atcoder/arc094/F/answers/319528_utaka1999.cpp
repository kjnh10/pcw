#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <set>
#define SIZE 200005
#define MOD 998244353

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

void chadd(int &X,int Y)
{
	X+=Y;
	if(X>=MOD) X-=MOD;
}
char str[SIZE];
int dp[2][3][3][3][2];

int main()
{
	scanf("%s",&str);
	int n=strlen(str);
	bool up=true;
	for(int i=0;i<n;i++)
	{
		if(str[i]!=str[0]) up=false;
	}
	if(up)
	{
		puts("1");
		return 0;
	}
	if(n==2)
	{
		puts("2");
		return 0;
	}
	if(n==3&&str[0]!=str[1]&&str[1]!=str[2]&&str[0]!=str[2])
	{
		puts("3");
		return 0;
	}
	int pos=0;
	dp[pos][2][2][0][0]=1;
	dp[pos][1][0][1][0]=1;
	dp[pos][0][1][2][0]=1;
	for(int i=1;i<n;i++)
	{
		pos^=1;
		memset(dp[pos],0,sizeof(dp[pos]));
		for(int a=0;a<3;a++)
		{
			for(int b=0;b<3;b++)
			{
				for(int c=0;c<3;c++)
				{
					for(int t=0;t<3;t++)//nxt
					{
						int na=a,nb=b;
						if(t==0)
						{
							na+=2,nb+=2;
							if(na>=3) na-=3;
							if(nb>=3) nb-=3;
						}
						else if(t==1)
						{
							na++;
							if(na>=3) na-=3;
						}
						else
						{
							nb++;
							if(nb>=3) nb-=3;
						}
						if(c==t)
						{
							chadd(dp[pos][na][nb][t][1],dp[pos^1][a][b][c][0]);
							chadd(dp[pos][na][nb][t][1],dp[pos^1][a][b][c][1]);
						}
						else
						{
							chadd(dp[pos][na][nb][t][0],dp[pos^1][a][b][c][0]);
							chadd(dp[pos][na][nb][t][1],dp[pos^1][a][b][c][1]);
						}
					}
				}
			}
		}
	}
	int b=0,c=0;
	up=true;
	for(int i=0;i<n;i++)
	{
		if(str[i]=='a')
		{
			b+=2,c+=2;
			b%=3,c%=3;
		}
		else if(str[i]=='b')
		{
			b++;
			b%=3;
		}
		else
		{
			c++;
			c%=3;
		}
		if(i>0&&str[i]==str[i-1])
		{
			up=false;
		}
	}
	int ret=up;
	for(int t=0;t<3;t++) chadd(ret,dp[pos][b][c][t][1]);
	printf("%d\n",ret);
	return 0;
}
