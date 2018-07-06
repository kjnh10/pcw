#include<bits/stdc++.h>
using namespace std;
#define LL long long

const LL maxn=3e5+10;

LL n,a[maxn];
LL pre[maxn],suf[maxn],Sum,Ans=-1e18;

priority_queue<LL,vector<LL>,greater<LL> > q1;
priority_queue<LL> q2;

int main()
{
#ifdef h10
	freopen("D.in","r",stdin);
	freopen("D.out","w",stdout);
#endif
	LL i;
	scanf("%lld",&n);
	for (i=1;i<=3*n;i++)
		scanf("%lld",&a[i]);

	Sum=0;
	for (i=1;i<=n;i++)
	{
		q1.push(a[i]);
		Sum+=a[i];
	}
	pre[n]=Sum;
	for (i=n+1;i<=2*n;i++)
	{
		q1.push(a[i]);
		Sum+=a[i];
		Sum-=q1.top();
		q1.pop();
		pre[i]=Sum;
	}

	Sum=0;
	for (i=3*n;i>2*n;i--)
	{
		q2.push(a[i]);
		Sum+=a[i];
	}
	suf[2*n+1]=Sum;
	for (i=2*n;i>=n;i--)
	{
		q2.push(a[i]);
		Sum+=a[i];
		Sum-=q2.top();
		q2.pop();
		suf[i]=Sum;
	}

	for (i=n;i<=2*n;i++)
		Ans=max(Ans,pre[i]-suf[i+1]);
	printf("%lld\n",Ans);
}
