#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
#include <functional>
#include <map>
#include <set>
#include <cmath>
#include <string>
#define SIZE 200005

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

struct BIT
{
	int bit[SIZE];
	
	void init()
	{
		memset(bit,0,sizeof(bit));
	}
	void add(int k,int x)
	{
		k++;
		while(k<SIZE)
		{
			bit[k]+=x;
			k+=k&-k;
		}
	}
	int get(int k)
	{
		k++;
		int ret=0;
		while(k>0)
		{
			ret+=bit[k];
			k-=k&-k;
		}
		return ret;
	}
	int get(int s,int t)
	{
		return get(t)-get(s-1);
	}
	int pos(int k)//k 番目
	{
		int l=0,r=SIZE;
		while(r-l>1)
		{
			int m=(l+r)/2;
			if(get(m)<k) l=m;
			else r=m;
		}
		return r;
	}
};
BIT bit;
ll sum[SIZE];

int main()
{
	int n;
	ll K;
	scanf("%d %lld",&n,&K);
	int sz=0;
	sum[sz++]=0;
	for(int i=0;i<n;i++)
	{
		scanf("%lld",&sum[sz]);
		sum[sz]-=K;
		sum[sz]+=sum[sz-1];
		sz++;
	}
	vector <ll> vx;
	for(int i=0;i<sz;i++) vx.push_back(sum[i]);
	sort(vx.begin(),vx.end());
	vx.erase(unique(vx.begin(),vx.end()),vx.end());
	ll ret=0;
	for(int i=0;i<sz;i++)
	{
		int pos=lower_bound(vx.begin(),vx.end(),sum[i])-vx.begin();
		ret+=bit.get(pos);
		bit.add(pos,1);
	}
	printf("%lld\n",ret);
	return 0;
}
