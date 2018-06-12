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
#define SIZE 100005
#define INF 100000000000000000LL

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

vector <P> vec[SIZE];
ll dp[SIZE];

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++)
	{
		int l,r,d;
		scanf("%d %d %d",&l,&r,&d);l--,r--;
		vec[l].push_back(P(r,d));
		vec[r].push_back(P(l,-d));
	}
	for(int i=0;i<n;i++) dp[i]=INF;
	for(int i=0;i<n;i++)
	{
		if(dp[i]==INF)
		{
			queue <int> que;
			que.push(i);
			dp[i]=0;
			while(!que.empty())
			{
				int v=que.front();que.pop();
				for(int j=0;j<vec[v].size();j++)
				{
					P p=vec[v][j];
					int to=p.first,c=p.second;
					if(dp[to]==INF)
					{
						dp[to]=dp[v]+(ll) c;
						que.push(to);
					}
					else if(dp[to]!=dp[v]+(ll) c)
					{
						puts("No");
						return 0;
					}
				}
			}
		}
	}
	puts("Yes");
	return 0;
}
