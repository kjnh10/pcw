#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<deque>
#include<string>
#include<string.h>
#include<vector>
#include<set>
#include<map>
#include<stdlib.h>
#include<cassert>
using namespace std;
const long long mod=1000000009;
const long long inf=mod*mod;
const long long d2=500000004;
const double EPS=1e-6;
const double PI=acos(-1.0);
int ABS(int a){return max(a,-a);}
long long ABS(long long a){return max(a,-a);}
int g[3100][3100];
int main(){
	int a;scanf("%d",&a);
	for(int i=0;i<a;i++)for(int j=0;j<a;j++)scanf("%d",&g[i][j]);
	long long ret=0;
	for(int i=0;i<a;i++)for(int j=0;j<a;j++){
		bool need=true;
		for(int k=0;k<a;k++){
			if(g[i][k]+g[k][j]<g[i][j]){
				printf("-1\n");return 0;
			}
			if(i!=k&&k!=j&&g[i][k]+g[k][j]==g[i][j])need=false;
		}
		if(need)ret+=g[i][j];
	}
	printf("%lld\n",ret/2);
}