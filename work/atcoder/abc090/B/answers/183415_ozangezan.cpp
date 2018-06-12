#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<deque>
#include<stack>
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
const double EPS=1e-13;
const double PI=acos(-1.0);
int ABS(int a){return max(a,-a);}
long long ABS(long long a){return max(a,-a);}
double ABS(double a){return max(a,-a);}
char t[7];
int main(){
	int a,b;scanf("%d%d",&a,&b);
	int ret=0;
	for(int i=a;i<=b;i++){
		sprintf(t,"%d",i);
		if(t[0]==t[4]&&t[1]==t[3])ret++;
	}printf("%d\n",ret);
}