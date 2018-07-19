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
#include<bitset>
#include<stdlib.h>
#include<cassert>
#include<time.h>
#include<bitset>
using namespace std;
const long long mod=998244353;
const long long inf=mod*mod;
const long long d2=(mod+1)/2;
const double EPS=1e-6;
const double PI=acos(-1.0);
int ABS(int a){return max(a,-a);}
long long ABS(long long a){return max(a,-a);}
int d[20][20];
int t[110][110];
int main(){
	int a,b;scanf("%d%d",&a,&b);
	for(int i=0;i<a;i++){
		for(int j=0;j<b;j++){
			scanf("%d",&d[i][j]);
		}
	}
	for(int i=0;i<110;i++){
		for(int j=0;j<110;j++){
			for(int k=0;k<a;k++)for(int l=0;l<b;l++){
				t[i][j]=max(t[i][j],d[k][l]-(k+1)*i-(l+1)*j);
			}
		}
	}
	for(int i=0;i<a;i++){
		for(int j=0;j<b;j++){
			int v=mod;
			for(int k=0;k<110;k++)for(int l=0;l<110;l++){
				v=min(v,t[k][l]+k*(i+1)+l*(j+1));
			}
			if(v!=d[i][j]){
				printf("Impossible\n");return 0;
			}
		}
	}
	printf("Possible\n");
	printf("%d %d\n",220,109+109+110*110);
	for(int i=0;i<109;i++){
		printf("%d %d X\n",i+1,i+2);
	}
	for(int i=0;i<109;i++){
		printf("%d %d Y\n",i+111,i+112);
	}
	for(int i=0;i<110;i++)for(int j=0;j<110;j++){
		printf("%d %d %d\n",i+1,220-j,t[i][j]);
	}
	printf("1 220\n");
}