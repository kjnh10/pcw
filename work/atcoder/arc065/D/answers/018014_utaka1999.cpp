#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <functional>
#include <string>
#define SIZE 200005

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

struct UF
{
	int par[SIZE],rank[SIZE];
	
	void init(int n)
	{
		for(int i=0;i<n;i++)
		{
			par[i]=i;
			rank[i]=1;
		}
	}
	int find(int x)
	{
		if(x==par[x]) return x;
		return par[x]=find(par[x]);
	}
	void unite(int x,int y)
	{
		x=find(x);
		y=find(y);
		if(x==y) return;
		if(rank[x]<rank[y])
		{
			par[x]=y;
		}
		else
		{
			par[y]=x;
			if(rank[x]==rank[y]) rank[x]++;
		}
	}
	bool same(int x,int y)
	{
		return find(x)==find(y);
	}
};
UF S,T;
vector <P> all;

int main()
{
	int n,k,l;
	scanf("%d %d %d",&n,&k,&l);
	S.init(n+2);
	T.init(n+2);
	for(int i=0;i<k;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);a--,b--;
		S.unite(a,b);
	}
	for(int i=0;i<l;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);a--,b--;
		T.unite(a,b);
	}
	for(int i=0;i<n;i++) all.push_back(P(S.find(i),T.find(i)));
	sort(all.begin(),all.end());
	for(int i=0;i<n;i++)
	{
		P p=P(S.find(i),T.find(i));
		int ans=upper_bound(all.begin(),all.end(),p)-lower_bound(all.begin(),all.end(),p);
		if(i!=0) printf(" ");
		printf("%d",ans);
	}puts("");
	return 0;
}
