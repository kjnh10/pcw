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
#define SIZE 100005

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

int X[SIZE],Y[SIZE];
vector <int> vx,vy;
set <P> sx[SIZE];
set <P> sy[SIZE];
set <P>::iterator it;
vector <int> mx[SIZE];
vector <int> my[SIZE];
int cnt[SIZE];
bool dp[SIZE];

int get_x(int x,int s,int t)//x 軸平行
{
	int pos=lower_bound(vx.begin(),vx.end(),x)-vx.begin();
	if(pos==vx.size()||vx[pos]!=x) return 0;
	x=pos;
	return upper_bound(mx[x].begin(),mx[x].end(),t)-lower_bound(mx[x].begin(),mx[x].end(),s);
}
int get_y(int y,int s,int t)//y 軸平行
{
	int pos=lower_bound(vy.begin(),vy.end(),y)-vy.begin();
	if(pos==vy.size()||vy[pos]!=y) return 0;
	y=pos;
	return upper_bound(my[y].begin(),my[y].end(),t)-lower_bound(my[y].begin(),my[y].end(),s);
}
int main()
{
	int n,a,b;
	scanf("%d %d %d",&n,&a,&b);a--,b--;
	for(int i=0;i<n;i++)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		X[i]=x+y;
		Y[i]=x-y;
		vx.push_back(X[i]);
		vy.push_back(Y[i]);
	}
	sort(vx.begin(),vx.end());
	vx.erase(unique(vx.begin(),vx.end()),vx.end());
	sort(vy.begin(),vy.end());
	vy.erase(unique(vy.begin(),vy.end()),vy.end());
	for(int i=0;i<n;i++)
	{
		int x=lower_bound(vx.begin(),vx.end(),X[i])-vx.begin();
		int y=lower_bound(vy.begin(),vy.end(),Y[i])-vy.begin();
		mx[x].push_back(Y[i]);
		my[y].push_back(X[i]);
		sx[x].insert(P(Y[i],i));
		sy[y].insert(P(X[i],i));
	}
	for(int i=0;i<vx.size();i++) sort(mx[i].begin(),mx[i].end());
	for(int i=0;i<vy.size();i++) sort(my[i].begin(),my[i].end());
	int c=max(abs(X[a]-X[b]),abs(Y[a]-Y[b]));
	for(int i=0;i<n;i++)
	{
		cnt[i]=get_x(X[i]-c,Y[i]-c,Y[i]+c)+get_x(X[i]+c,Y[i]-c,Y[i]+c);
		cnt[i]+=get_y(Y[i]-c,X[i]-c+1,X[i]+c-1)+get_y(Y[i]+c,X[i]-c+1,X[i]+c-1);
		//printf("%d %d : %d\n",X[i],Y[i],cnt[i]);
	}
	dp[a]=dp[b]=true;
	queue <int> que;
	que.push(a);
	que.push(b);
	while(!que.empty())
	{
		int i=que.front();que.pop();
		//printf("%d\n",i);
		int pos=lower_bound(vx.begin(),vx.end(),X[i]-c)-vx.begin();
		if(pos<vx.size()&&vx[pos]==X[i]-c)
		{
			while(1)
			{
				it=sx[pos].lower_bound(P(Y[i]-c,-1));
				if(it==sx[pos].end()||it->first>Y[i]+c) break;
				int v=it->second;
				if(!dp[v])
				{
					dp[v]=true;
					que.push(v);
				}
				sx[pos].erase(it);
			}
		}
		pos=lower_bound(vx.begin(),vx.end(),X[i]+c)-vx.begin();
		if(pos<vx.size()&&vx[pos]==X[i]+c)
		{
			while(1)
			{
				it=sx[pos].lower_bound(P(Y[i]-c,-1));
				if(it==sx[pos].end()||it->first>Y[i]+c) break;
				int v=it->second;
				if(!dp[v])
				{
					dp[v]=true;
					que.push(v);
				}
				sx[pos].erase(it);
			}
		}
		pos=lower_bound(vy.begin(),vy.end(),Y[i]-c)-vy.begin();
		if(pos<vy.size()&&vy[pos]==Y[i]-c)
		{
			while(1)
			{
				it=sy[pos].lower_bound(P(X[i]-c,-1));
				if(it==sy[pos].end()||it->first>X[i]+c) break;
				int v=it->second;
				if(!dp[v])
				{
					dp[v]=true;
					que.push(v);
				}
				sy[pos].erase(it);
			}
		}
		pos=lower_bound(vy.begin(),vy.end(),Y[i]+c)-vy.begin();
		if(pos<vy.size()&&vy[pos]==Y[i]+c)
		{
			while(1)
			{
				it=sy[pos].lower_bound(P(X[i]-c,-1));
				if(it==sy[pos].end()||it->first>X[i]+c) break;
				int v=it->second;
				if(!dp[v])
				{
					dp[v]=true;
					que.push(v);
				}
				sy[pos].erase(it);
			}
		}
	}
	ll ret=0;
	for(int i=0;i<n;i++)
	{
		if(dp[i])
		{
			//printf("%d\n",i);
			ret+=cnt[i];
		}
	}
	printf("%lld\n",ret/2LL);
	return 0;
}
