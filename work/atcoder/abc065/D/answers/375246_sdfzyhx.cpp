#include<cstdio>
#include<algorithm>
using namespace std;
struct node
{
	int x,y,id;
}a[200010];
struct edge
{
	int u,v,d;
	bool operator < (const edge &e) const
	{
		return d<e.d;
	}
}g[300010];
int cmpx(node a,node b)
{
	return a.x<b.x;
}
int cmpy(node a,node b)
{
	return a.y<b.y;
}
int n,m,fa[200010];
int find(int x)
{
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
int main()
{
	int ans=0;
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		fa[i]=i;
		scanf("%d%d",&a[i].x,&a[i].y);
		a[i].id=i;
	}
	sort(a+1,a+n+1,cmpx);
	for (int i=1;i<n;i++) g[++m]=(edge){a[i].id,a[i+1].id,a[i+1].x-a[i].x};
	sort(a+1,a+n+1,cmpy);
	for (int i=1;i<n;i++) g[++m]=(edge){a[i].id,a[i+1].id,a[i+1].y-a[i].y};
	sort(g+1,g+m+1);
	for (int i=1;i<=m;i++)
		if (find(g[i].u)!=find(g[i].v))
		{
			ans+=g[i].d;
			fa[fa[g[i].u]]=fa[g[i].v];
		}
	printf("%d\n",ans);
}