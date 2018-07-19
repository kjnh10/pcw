#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 200005

using namespace std;
typedef long long int ll;

int A[SIZE];
int imos1[SIZE];
ll imos2[SIZE];

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	int now;
	scanf("%d",&now);now--;
	ll all=0;
	for(int i=1;i<n;i++)
	{
		int to;
		scanf("%d",&to);to--;
		now%=m;
		if(now>to) to+=m;
		all+=to-now;
		imos1[now+1]++;
		imos1[to+1]--;
		imos2[now+1]+=now;
		imos2[to+1]-=now;
		now=to;
	}
	for(int i=1;i<2*m;i++)
	{
		imos1[i]+=imos1[i-1];
		imos2[i]+=imos2[i-1];
	}
	ll ret=all;
	for(int i=0;i<m;i++)
	{
		int a=imos1[i];
		ll b=imos2[i];
		ll nxt=all;
		nxt-=(ll) a*(ll) i-b-a;
		a=imos1[i+m],b=imos2[i+m];
		nxt-=(ll) a*(ll) (i+m)-b-a;
		ret=min(ret,nxt);
	}
	printf("%lld\n",ret);
	return 0;
}
