#include <bits/stdc++.h>
#define Maxn 18
#define modp1 998244353
#define modp2 100000007
using namespace std;
int n,m;
map<pair<int,int>,int> mp;
char s[Maxn][Maxn],s1[Maxn][Maxn];
int ch[Maxn];
bool vis[Maxn];
bool ans=false;
void calc()
{
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++)
			s1[i][j]=s[i][j];
	for (int i=1;i<=(n+1)/2;i++)
		if (ch[i]!=0&&ch[i]<=n)
		{
			for (int j=1;j<=m;j++)
				swap(s1[i][j],s1[ch[i]][j]);
		}
	int cnt=0;
	mp.clear();
	for (int i=1;i<=m;i++)
	{
		int now1=0,now2=0;
		for (int j=1;j<=n;j++)
		{
			now1=(29LL*now1+s1[j][i]-'a'+1)%modp1;
			now2=(29LL*now2+s1[j][i]-'a'+1)%modp2;
		}
		if (mp[make_pair(now1,now2)])
		{
			--cnt;
			--mp[make_pair(now1,now2)];
		} else
		{
			++cnt;
			now1=0,now2=0;
			for (int j=n;j;j--)
			{
				now1=(29LL*now1+s1[j][i]-'a'+1)%modp1;
				now2=(29LL*now2+s1[j][i]-'a'+1)%modp2;
			}
			++mp[make_pair(now1,now2)];
		}
	}
	if (cnt<=1) ans=true;
}
void dfs(int x)
{
	if (ans) return;
	if (x<=(n+1)/2)
	{
		for (int i=x+1;i<=2*((n+1)/2)&&(!ans);i++)
			if (!vis[i])
			{
				ch[x]=i;
				ch[i]=x;
				dfs(x+1);
				ch[i]=0;
			}
	}
	else calc();
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
		scanf("%s",s[i]+1);
	memset(vis,false,sizeof(vis));
	dfs(1);
	if (ans) printf("YES\n"); else printf("NO\n");
	return 0;
}
