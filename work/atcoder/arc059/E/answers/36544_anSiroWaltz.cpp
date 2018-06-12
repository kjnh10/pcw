#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;
const int mod=1000000007;

int a[410],b[410],pow0[410][410],dp[410][410];

int main()
{
    #ifdef waltz
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int n,c;scanf("%d%d",&n,&c);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    for (int i=1;i<=n;i++) scanf("%d",&b[i]);
    for (int i=1;i<=400;i++)
    {
        pow0[i][0]=1;
        for (int j=1;j<=400;j++) pow0[i][j]=ll(pow0[i][j-1])*i%mod;
    }
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;
    for (int i=1;i<=n;i++)
    {
        for (int j=0;j<=c;j++)
        {
            int s=0;
            for (int k=a[i];k<=b[i];k++) s=(s+pow0[k][j])%mod;
            for (int k=j;k<=c;k++) dp[i][k]=(ll(dp[i-1][k-j])*s+dp[i][k])%mod;
        }
    }
    printf("%d\n",dp[n][c]);
    return 0;
}
