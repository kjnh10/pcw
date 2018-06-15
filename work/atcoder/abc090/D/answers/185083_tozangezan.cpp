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

int main(){
    int a,b;scanf("%d%d",&a,&b);
    long long ret=0;
    for(int i=b+1;i<=a;i++){
        for(int j=0;j<=a/i;j++){
            int nd=j*i;
            int am=min(1+a-nd,i);
            int rm=max(0,am-b);
      //      printf("%d %d: %d\n",i,j,rm);
            ret+=rm;
            if(rm&&j==0&&b==0)ret--;
        }
    }
    printf("%lld\n",ret);
}