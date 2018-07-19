#include<bits/stdc++.h>
#define N 2009
using namespace std;

int m,n,ans,a[N][N],b[N][N],c[N],q[N],lf[N],rg[N];
char s[N];
int main(){
	scanf("%d%d",&m,&n);
	int i,j,k;
	for (i=1; i<=m; i++){
		scanf("%s",s+1);
		for (j=1; j<=n; j++) a[i][j]=(s[j]=='#');
	}
	for (i=1; i<=m; i++)
		for (j=2; j<=n; j++)
			b[i][j]=(a[i][j]^a[i+1][j])==(a[i][j-1]^a[i+1][j-1])?b[i-1][j]+1:0;
	for (i=1; i<=m; i++){
		for (j=2; j<=n; j++) c[j]=1+b[i-1][j];
		//if (i==2) for (j=2; j<=n; j++) cout<<c[j]<<' ';puts("");
		q[k=1]=1; c[1]=-2; c[n+1]=-1;
		for (j=2; j<=n+1; j++){
			for (; c[j]<=c[q[k]]; k--) rg[q[k]]=j;
			lf[j]=q[k]; q[++k]=j;
		}
		for (j=2; j<=n; j++){
			//cout<<j<<' '<<lf[j]<<' '<<rg[j]<<endl;
			ans=max(ans,c[j]*(rg[j]-lf[j]));
		}
	}
	printf("%d\n",max(ans,max(m,n)));
	return 0;
}
