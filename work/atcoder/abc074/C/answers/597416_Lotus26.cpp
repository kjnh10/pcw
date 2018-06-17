#include <cstdio>
#include <cmath>
#include <vector>
#include <iostream>
#include <map>
#include <queue>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
#define mst(a,b) memset((a),(b),sizeof(a))
#define rush() int T;scanf("%d",&T);while(T--)

typedef long long ll;
const int maxn = 100005;
const ll mod = 1e9+7;
const int INF = 0x3f3f3f3f;
const double eps = 1e-9;

int n,m;
int a[maxn];
char s[maxn];

int main()
{
    int a,b,c,d,e,f;
    scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
    int ans1,ans2;
    double rate=-1;
    for(int i=0;100*a*i<=f;i++)
    for(int j=0;100*a*i+100*b*j<=f;j++)
    {
        int sum1=100*a*i+100*b*j;
        if(sum1==0) continue;
        int res=f-sum1;
        for(int ii=0;ii*c<=res;ii++)
        for(int jj=0;ii*c+jj*d<=res;jj++)
        {
            int sum2=ii*c+jj*d;
            if(sum1/100*e>=sum2)
            {
                if(sum2*1.0/sum1>=rate)
                {
                    rate=sum2*1.0/sum1;
                    ans1=sum1;
                    ans2=sum2;
                }
            }
        }
    }
    printf("%d %d\n",ans1+ans2,ans2);
    return 0;
}
