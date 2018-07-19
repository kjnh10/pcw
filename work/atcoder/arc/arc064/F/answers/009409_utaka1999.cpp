#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
#include <queue>
#include <functional>
#include <set>
#include <map>
#include <deque>
#define MOD 1000000007

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

vector <int> dv;
vector <ll> dp;

ll mpow(ll n,ll t)
{
	if(t==0) return 1LL;
	ll ret=mpow(n,t/2);
	ret=ret*ret%MOD;
	if(t%2==1) ret=ret*n%MOD;
	return ret;
}
int main()
{
	int n,k;
	scanf("%d %d",&n,&k);
	for(int i=1;i*i<=n;i++)
	{
		if(n%i==0)
		{
			dv.push_back(i);
			if(i<n/i) dv.push_back(n/i);
		}
	}
	sort(dv.begin(),dv.end());
	dp.resize(dv.size());
	ll ret=0;
	for(int i=0;i<dv.size();i++)
	{
		dp[i]=mpow(k,(dv[i]+1)/2);
		for(int j=0;j<i;j++)
		{
			if(dv[i]%dv[j]==0)
			{
				dp[i]-=dp[j];
				if(dp[i]<0) dp[i]+=MOD;
			}
		}
		ret+=dp[i]*(ll) (dv[i]%2==1?dv[i]:dv[i]/2)%MOD;
		if(ret>=MOD) ret-=MOD;
	}
	printf("%lld\n",ret);
	return 0;
}
