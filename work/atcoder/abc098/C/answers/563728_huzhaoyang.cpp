#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
char s[300002];
int f1[300002],f2[300002],g1[300002],g2[300002];
int main(){
	int n,t,ans=0x3f3f3f3f;
	scanf("%d%s",&n,s);
	for(int i=0;s[i];i++)f1[i]=f1[i-1]+(s[i]=='W');
	for(int i=0;s[i];i++)g1[i]=g1[i-1]+(s[i]=='E');
	for(int i=n-1;i>=0;i--)f2[i]=f2[i+1]+(s[i]=='W');
	for(int i=n-1;i>=0;i--)g2[i]=g2[i+1]+(s[i]=='E');
	ans=min(f2[0],g2[0]);
	for(int i=0;s[i];i++)ans=min(ans,f1[i]+g2[i+1]);
	printf("%d",ans);
}