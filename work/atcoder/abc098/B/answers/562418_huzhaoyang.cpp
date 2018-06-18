#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
char s[101];
bool vis[101],flag[101];
int main(){
	int n,t,ans=0;
	scanf("%d%s",&n,s);
	for(int i=0;s[i];i++){
		vis[s[i]-'a']=true;
		t=0;
		memset(flag,0,sizeof(flag));
		for(int j=i+1;s[j];j++)
			if (vis[s[j]-'a'])flag[s[j]-'a']=true;
		for(int j=0;j<26;j++)t+=flag[j];
		ans=max(ans,t);
	}
	printf("%d",ans);
}