#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double llf;
#define ft first
#define sd second
const int N=1e5+5,K=1000+5;
int x[N],y[N];
bool c[N];
int cnt[K];
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	{
		char chr;
		for(int i=1;i<=n;++i){
			scanf("%d%d%*c%c",x+i,y+i,&chr);
			c[i]=(x[i]/k&1)^(y[i]/k&1)^(chr=='B');
		}
	}
	
//	printf("c=");
//	for(int i=1;i<=n;++i)printf("%d ",c[i]);
//	puts("");
	
	int ans=0;
	for(int t=2;t--;)
		for(int i=0;i<k;++i){
			memset(cnt,0,sizeof(cnt));
			int now=0;
			for(int j=1;j<=n;++j){
				now+=c[j];
				cnt[y[j]%k]+=c[j]?-1:1;
			}
			for(int j=0;j<k;++j){
				ans=max(ans,now);
				now+=cnt[j];
			}
			for(int j=1;j<=n;++j)
				if(x[j]%k==i)
					c[j]^=1;
		}
	printf("%d\n",ans);
}