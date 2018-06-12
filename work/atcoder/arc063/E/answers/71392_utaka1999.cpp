#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <string>
#include <cmath>
#define SIZE 100005
#define INF 1000000000

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

vector <int> vec[SIZE];
int L[SIZE],R[SIZE];
int id[SIZE];
bool ans;

void solve(int v=0,int p=-1)
{
	L[v]=-INF-1,R[v]=INF+1;
	if(id[v]!=-1) L[v]=R[v]=id[v];
	for(int i=0;i<vec[v].size();i++)
	{
		int to=vec[v][i];
		if(to!=p)
		{
			solve(to,v);
			if(L[to]<-INF/2) continue;
			if(L[v]<-INF/2)
			{
				L[v]=L[to]-1;
				R[v]=R[to]+1;
			}
			else
			{
				if(abs(L[to])%2==abs(L[v])%2)
				{
					ans=false;
					return;
				}
				L[v]=max(L[v],L[to]-1);
				R[v]=min(R[v],R[to]+1);
			}
		}
	}
	if(L[v]>R[v]) ans=false;
}
void make(int v=0,int p=-1)
{
	if(v==0&&id[v]==-1) id[v]=L[v];
	for(int i=0;i<vec[v].size();i++)
	{
		int to=vec[v][i];
		if(to!=p)
		{
			if(id[to]==-1)
			{
				if(L[to]<=id[v]-1&&id[v]-1<=R[to]) id[to]=id[v]-1;
				else id[to]=id[v]+1;
			}
			make(to,v);
		}
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n-1;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);a--;b--;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
	memset(id,-1,sizeof(id));
	int Q;
	scanf("%d",&Q);
	while(Q--)
	{
		int v,p;
		scanf("%d %d",&v,&p);v--;
		id[v]=p;
	}
	ans=true;
	solve();
	if(!ans)
	{
		puts("No");
	}
	else
	{
		make();
		puts("Yes");
		for(int i=0;i<n;i++) printf("%d\n",id[i]);
	}
	return 0;
}
