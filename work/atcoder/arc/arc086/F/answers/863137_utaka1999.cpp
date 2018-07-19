#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <functional>
#include <stack>
#include <string>
#include <cmath>
#include <map>
#define SIZE 205
#define MOD 1000000007
#define B1 89793

using namespace std;
typedef long long int ll;
typedef pair <ll,ll> P;
typedef unsigned long long int ull;

ll A[SIZE];
map < vector <ll>,vector <P> > mp;
map < vector <ll>,vector <P> >::iterator it;

int get(ll a,ll b)
{
	int ret=0;
	for(int i=62;i>=0;i--)
	{
		if(!(a>>i&1)&&(b>>i&1))
		{
			if(a!=0) ret++;
			break;
		}
		else if(a>>i&1)
		{
			a-=1LL<<i;
			b-=1LL<<i;
			ret++;
		}
	}
	return ret;
}
int main()
{
	int n;
	ll K;
	scanf("%d %lld",&n,&K);
	for(int i=0;i<n;i++) scanf("%lld",&A[i]);
	ll ret=0;
	for(int i=0;i<63;i++)
	{
		vector <ll> vt;
		for(int j=0;j<n;j++) vt.push_back(A[j]%(1LL<<i)+1);
		vt.push_back(0);
		vt.push_back(1LL<<i);
		sort(vt.begin(),vt.end());
		vt.erase(unique(vt.begin(),vt.end()),vt.end());
		for(int j=0;j+1<vt.size();j++)
		{
			ll g=vt[j];
			vector <ll> now;
			bool up=true;
			for(int k=0;k<n;k++)
			{
				ll zan=A[k]%(1LL<<i);
				ll gn=A[k]>>i;
				if(zan<g) gn--;
				if(gn<0) up=false;
				now.push_back(gn);
			}
			ll nd=0;
			ll a=vt[j],b=vt[j+1]-1;
			if(a>b) continue;
			//a～bでbitcount最小求める
			int t=get(a,b)+i;
			if(up&&t<=K)
			{
				//puts("");
				//printf("%d %lld %lld : %d\n",i,a,b,t);
				//for(int k=0;k<n;k++) printf("%d ",now[k]);puts("");
				ll mn=now[0];
				for(int k=0;k<n;k++) mn=min(mn,now[k]);
				for(int k=0;k<n;k++) now[k]-=mn;
				ll low=max(0LL,mn-(K-t));/*
				ull gh=0;
				for(int k=0;k<n;k++)
				{
					gh=gh*B1+(ll) (now[k]+1);
				}*/
				mp[now].push_back(P(low,mn));
			}
		}
	}
	for(it=mp.begin();it!=mp.end();it++)
	{
		vector <P> vx=it->second;
		sort(vx.begin(),vx.end());
		P now=vx[0];
		for(int i=0;i<vx.size();i++)
		{
			P p=vx[i];
			if(now.second<p.first)
			{
				ret+=now.second-now.first+1;
				ret%=MOD;
				now=p;
			}
			now.second=max(now.second,p.second);
		}
		ret+=now.second-now.first+1;
		ret%=MOD;
	}
	printf("%lld\n",ret%MOD);
	return 0;
}
