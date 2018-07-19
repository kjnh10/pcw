#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n,a[200001],b[200001];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	int m=0;
	for(int i=n;i>1 && m<2;i--)
		if(a[i]==a[i-1])
			b[++m]=a[i],--i;
	if(m<2)
		puts("0");
	else
		printf("%lld\n",(ll)b[1]*b[2]);
	return 0;
}