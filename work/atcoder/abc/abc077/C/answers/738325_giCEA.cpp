#include<cstdio>
#include<algorithm>

int n;
long long a[100010];
long long b[100010];
long long c[100010];

int atob[100010];
int btoc[100010];
long long bS[100010];
long long ans;

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%lld",a+i); std::sort(a,a+n);
	for(int i=0;i<n;i++) scanf("%lld",b+i); std::sort(b,b+n);
	for(int i=0;i<n;i++) scanf("%lld",c+i); std::sort(c,c+n);

	for(int i=0,j=0;i<n;)
	{
		if(a[i]<b[j]) atob[i++]=j;
		else if(j<n) j++;
		else atob[i++]=-1;
	}

	for(int i=0,j=0;i<n;)
	{
		if(b[i]<c[j]) btoc[i++]=j;
		else if(j<n) j++;
		else btoc[i++]=-1;
	}

	for(int i=n-1;i>=0;i--) if(btoc[i]>=0) bS[i]=bS[i+1]+(n-btoc[i]);

	for(int i=n-1;i>=0;i--) if(atob[i]>=0) ans+=bS[atob[i]];

	printf("%lld\n",ans);

	return 0;
}
