#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <functional>
#include <set>
#include <map>
#define SIZE 500005
#define EPS 1e-10

using namespace std;
typedef long long int ll;
typedef pair <double,int> P;

P st[SIZE];

int main()
{
	int n,L;
	scanf("%d %d",&n,&L);
	int s=0,sz=0;
	double sum=0.0;
	for(int i=0;i<n;i++)
	{
		int t,v;
		scanf("%d %d",&t,&v);
		if(i>0)
		{
			int zan=v;
			while(zan>0)
			{
				if(st[s].second>zan)
				{
					st[s].second-=zan;
					sum-=st[s].first*(double) zan;
					break;
				}
				else
				{
					sum-=st[s].first*(double) st[s].second;
					zan-=st[s].second;
					s++;
				}
			}
		}
		sum+=(double) t*(double) v;
		P p=P(t,v);
		while(sz>s&&st[sz-1].first+EPS>p.first)
		{
			P q=st[--sz];
			P r=P((q.first*(double) q.second+p.first*(double) p.second)/(double) (p.second+q.second),p.second+q.second);
			p=r;
		}
		//printf("%f %d\n",p.first,p.second);
		st[sz++]=p;
		printf("%.10f\n",sum/(double) L);
	}
	return 0;
}
