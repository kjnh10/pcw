#include <stdio.h>
#include <stdlib.h>
using namespace std;

int n,m,i,j,k,l,r;
int a[100005];
long long ans,tmp,ans_sum,sum1[200005],sum2[200005];

int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i)scanf("%d",&a[i]);
	for(i=1;i<n;++i)
	{
		l=a[i];r=a[i+1];
		if(r<l)r+=m;
		ans_sum+=r-l;
		if(l+1<r)
		{
			++sum1[l+2];sum2[l+2]-=l+1;
			--sum1[r+1];sum2[r+1]+=l+1;
		}
	}
	for(i=1;i<=m+m;++i)sum1[i]+=sum1[i-1],sum2[i]+=sum2[i-1];
	for(i=1;i<=m;++i)
	{
		tmp=sum1[i]*i+sum2[i]+sum1[i+m]*(i+m)+sum2[i+m];
		if(tmp>ans)ans=tmp;
	}
	printf("%lld\n",ans_sum-ans);
}