#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
#define LL long long
#define maxn 500500
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define dow(i,l,r) for(int i=r;i>=l;i--)
using namespace std;

int f[maxn],num[maxn],n,m,f2[maxn];
int main()
{
	scanf("%d %d",&n,&m);
	rep(i,0,n-1) scanf("%d",num+i);
	sort(num,num+n);
	int r=n-1;
	while (num[r]>=m) --r;
	f[0]=1;
//	rep(i,0,r) printf("%d %d\n",i,num[i]); 
	int sum=0,ans=0;
	memset(f,0,sizeof(f));
	f[0]=1;
	rep(i,0,r) 
		dow(j,num[i],m+num[i]-1)
			f[j]+=f[j-num[i]];
//	rep(j,1,m*2) printf("%d %d\n",j,f[j]);
	rep(i,m,m*2) sum+=f[i];
	rep(i,0,r) {
		rep(j,0,m*2) f2[j]=f[j];
		rep(j,num[i],m+num[i]-1)
			f2[j]-=f2[j-num[i]];
		int now=0;
		rep(j,m,m*2) now+=f2[j];
	//	rep(j,1,m*2) printf("%d %d\n",j,f2[j]);
	//	printf("%d %d\n",now,sum);
		if (now==sum) ++ans;
	}
	printf("%d\n",ans);
	return 0;
}  