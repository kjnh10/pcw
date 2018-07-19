#include<bits/stdc++.h>
using namespace std;

template <typename T> void chmax(T &x,const T &y)
{
	if(x<y)x=y;
}
template <typename T> void chmin(T &x,const T &y)
{
	if(x>y)x=y;
}
typedef long long ll;
typedef unsigned int ui;
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)
const int N=1e5+5,M=2e5+5,inf=1e9+1;
int t[N];
struct edge
{
	int to,next,w;
};
edge l[M*2];int e;
int g[N],mn,mx;

void out()
{
	puts("No");exit(0);
}
void dfs(int x)
{
	for(int i=t[x];i;i=l[i].next)
	{
		int y=l[i].to;
		int g_y=g[x]+l[i].w;
		if(g_y>=inf)out();
		chmin(mn,g_y);chmax(mx,g_y);
		if(g[y]>inf){g[y]=g_y;dfs(y);}
		else 
		if(g[y]!=g_y)out();
	}
}

int main()
{
	//freopen("1.in","r",stdin);
	int	n,m; 
	cin>>n>>m;
	rep(i,1,m)
	{
		int x,y,w;
		scanf("%d %d %d",&x,&y,&w);
		l[++e]=(edge){y,t[x],w};t[x]=e;
		l[++e]=(edge){x,t[y],-w};t[y]=e;
	}
	memset(g,(1<<7)-1,sizeof(g));
	rep(x,1,n)
	if(g[x]>inf)
	{
		mx=mn=0;
		g[x]=0;dfs(x);
		if(mx-mn>=inf)out();
	}
	puts("Yes");
}
