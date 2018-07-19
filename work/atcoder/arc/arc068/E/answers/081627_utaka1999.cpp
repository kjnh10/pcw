#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 300005

using namespace std;
typedef long long int ll;

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
};
BIT bit;
vector <int> dv[SIZE];
vector <int> back[SIZE];
int ans[SIZE];
int cnt[SIZE];

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)
	{
		int l,r;
		scanf("%d %d",&l,&r);
		cnt[r]++;
		back[l-1].push_back(r);
	}
	bit.init();
	for(int i=1;i<=m;i++)
	{
		for(int j=i;j<=m;j+=i) dv[j].push_back(i);
	}
	for(int i=m;i>=1;i--)
	{
		bit.add(i,cnt[i]);
		for(int j=0;j<back[i].size();j++) bit.add(back[i][j],-1);
		for(int j=0;j<dv[i].size();j++)
		{
			int v=dv[i][j];
			ans[v]+=bit.get(i+v-1);
		}
	}
	for(int i=1;i<=m;i++) printf("%d\n",ans[i]);
	return 0;
}
