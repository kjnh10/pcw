#include<iostream>
#include<cstdio>
using namespace std;
int n;
long long ans;
long long gcd(long long x,long long y)
{
	if(y==0LL)return x;
	return gcd(y,x%y);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		long long t;
		scanf("%lld",&t);
		if(i==1)ans=t;
		else ans=ans/gcd(ans,t)*t;
	}
	printf("%lld",ans);
	return 0;
} 