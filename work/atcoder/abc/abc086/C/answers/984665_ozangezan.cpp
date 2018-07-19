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

int main(){
	int a;scanf("%d",&a);
	int x=0;
	int y=0;
	int t=0;
	for(int i=0;i<a;i++){
		int p,q,r;
		scanf("%d%d%d",&p,&q,&r);
		if(ABS(q-x)+ABS(r-y)>p-t||(ABS(q-x)+ABS(r-y))%2!=(p-t)%2){
			printf("No\n");return 0;
		}
		x=q;y=r;t=p;
	}
	printf("Yes\n");
}