#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <set>
#include <map>
#include <functional>
#include <string>
#define SIZE 200005
#define INF 100000000000000000LL
#define MOD 1000000007

using namespace std;
typedef long long int ll;
typedef pair <ll,int> P;

struct edge
{
	int to,cost;
	edge(int to=0,int cost=0):to(to),cost(cost){}
};
vector <edge> vec[SIZE];
ll dist[SIZE];
ll ds[SIZE],dt[SIZE];
ll ws[SIZE],wt[SIZE];
ll way[SIZE];
int U[SIZE],V[SIZE];
ll L[SIZE];
int n,m;

void dijkstra(int v)
{
	for(int i=0;i<n;i++) dist[i]=INF;
	dist[v]=0;
	way[v]=1;
	priority_queue <P,vector <P>,greater <P> > que;
	que.push(P(0,v));
	while(!que.empty())
	{
		P p=que.top();que.pop();
		int u=p.second;
		if(dist[u]<p.first) continue;
		for(int i=0;i<vec[u].size();i++)
		{
			edge e=vec[u][i];
			if(dist[e.to]>dist[u]+e.cost)
			{
				dist[e.to]=dist[u]+e.cost;
				que.push(P(dist[e.to],e.to));
				way[e.to]=way[u];
			}
			else if(dist[e.to]==dist[u]+e.cost)
			{
				way[e.to]+=way[u];
				if(way[e.to]>=MOD) way[e.to]-=MOD;
			}
		}
	}
}
int main()
{
	scanf("%d %d",&n,&m);
	int s,t;
	scanf("%d %d",&s,&t);s--,t--;
	for(int i=0;i<m;i++)
	{
		int u,v,d;
		scanf("%d %d %d",&u,&v,&d);u--,v--;
		vec[u].push_back(edge(v,d));
		vec[v].push_back(edge(u,d));
		U[i]=u,V[i]=v;
		L[i]=d;
	}
	dijkstra(s);
	for(int i=0;i<n;i++) ds[i]=dist[i];
	for(int i=0;i<n;i++) ws[i]=way[i];
	dijkstra(t);
	for(int i=0;i<n;i++) dt[i]=dist[i];
	for(int i=0;i<n;i++) wt[i]=way[i];
	ll ret=ws[t]*ws[t]%MOD;
	ll mn=ds[t];
	for(int i=0;i<n;i++)
	{
		if(mn==ds[i]+dt[i]&&ds[i]==dt[i])
		{
			ret-=(ws[i]*ws[i]%MOD)*(wt[i]*wt[i]%MOD)%MOD;
			if(ret<0) ret+=MOD;
		}
	}
	//printf("%lld : %lld\n",mn,ret);
	for(int i=0;i<m;i++)
	{
		int u=U[i],v=V[i];
		if(ds[u]>ds[v]) swap(u,v);//ds[u]<ds[v]
		if(ds[u]+L[i]+dt[v]==mn)
		{
			ll a=ds[u],b=ds[u]+L[i];
			ll c=dt[v],d=dt[v]+L[i];
			if(max(a,c)<min(b,d))
			{
				ret-=(ws[u]*ws[u]%MOD)*(wt[v]*wt[v]%MOD)%MOD;
				if(ret<0) ret+=MOD;
			}
		}
	}
	printf("%lld\n",ret);
	return 0;
}
