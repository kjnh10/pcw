#include <bits/stdc++.h>
using namespace std;

const int mo=int(1e9+7);
int n,m,p[200010],id[200010],ans;
vector <int> son[200010],f[200010],g[200010],s,tim;

int qpow(int a,int b)
{
	int x=a;  a=1;
	while (b)
		{
			if (b&1)  a=1LL*a*x%mo;
			x=1LL*x*x%mo,b>>=1;
		}
	return a;
}

void dfs(int x)
{
	int hs=-1,ID;
	for (auto y:son[x])
		{
			dfs(y);
			if ((hs<0)||(f[id[y]].size()>f[id[hs]].size()))  hs=y;
		}
	if (hs<0)
		{
			id[x]=++m,f[m].push_back(1),g[m].push_back(1);
			return;
		}
	ID=id[x]=id[hs];
	for (auto y:son[x])
		if (y!=hs)
			{
				int d=f[ID].size()-f[id[y]].size();
				for (int i=0; i<f[id[y]].size(); i++)
					{
						if (tim[i+d]!=x)
							s[i+d]=(qpow(2,g[ID][i+d])+mo-f[ID][i+d])%mo,tim[i+d]=x;
						f[ID][i+d]=1LL*f[ID][i+d]*(qpow(2,g[id[y]][i])+mo-f[id[y]][i])%mo;
						f[ID][i+d]=(f[ID][i+d]+1LL*s[i+d]*f[id[y]][i])%mo;
						g[ID][i+d]+=g[id[y]][i];
						s[i+d]=1LL*s[i+d]*(qpow(2,g[id[y]][i])+mo-f[id[y]][i])%mo;
					}
			}
	f[id[x]].push_back(1),g[id[x]].push_back(1);
}

void work()
{
	scanf("%d",&n),s.resize(n+1),tim.resize(n+1,-1);
	for (int i=1; i<=n; i++)
		scanf("%d",&p[i]),son[p[i]].push_back(i);
	dfs(0);
	for (int i=0; i<f[id[0]].size(); i++)
		ans=(ans+1LL*f[id[0]][i]*qpow(2,n+1-g[id[0]][i]))%mo;
	printf("%d",ans);
}

int main()
{
	work();
	return 0;
}
