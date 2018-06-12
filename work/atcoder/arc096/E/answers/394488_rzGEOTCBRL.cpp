#include <cstdio>
using namespace std;
#define N 3005
int n,m,i,j,pw[N],ni[N],s[N][N];
inline int qmi(int di,int zhi,int Mod)
{
	int ret=1,x=di;
	while (zhi){
		if (zhi&1) ret=1LL*ret*x%Mod;x=1LL*x*x%Mod;zhi>>=1;
	}return ret;
}
int main()
{
	scanf("%d%d",&n,&m);pw[0]=1;
	for (i=1;i<=n;i++) pw[i]=1LL*pw[i-1]*i%m;
	ni[n]=qmi(pw[n],m-2,m);
	for (i=n;i>=1;i--) ni[i-1]=1LL*ni[i]*i%m;
	s[0][0]=1;
	for (i=1;i<=n+1;i++)
	for (j=1;j<=i;j++) s[i][j]=(1LL*j*s[i-1][j]+s[i-1][j-1])%m;
	int ans=0;
	for (i=0;i<=n;i++){
		int gh=qmi(2,qmi(2,n-i,m-1),m);
		for (j=0;j<=i;j++) ans=(1LL*((i&1)?(-1):1)*gh*pw[n]%m*ni[i]%m*ni[n-i]%m*qmi(2,1LL*(n-i)*j%(m-1),m)%m*s[i+1][j+1]+ans)%m;
	}printf("%d\n",(ans+m)%m);
	return 0;
}