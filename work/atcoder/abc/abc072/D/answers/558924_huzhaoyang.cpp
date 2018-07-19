#include<cstdio>
#include<algorithm>
using namespace std;
int n,ans,a[100001];
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)scanf("%d",&a[i]);
	for (int i=1;i<=n;i++)
		if (a[i]==i)
		{
			swap(a[i+1],a[i]);
			ans++;
		}
	printf("%d",ans);
}