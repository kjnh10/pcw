#include <bits/stdc++.h>
#include <iomanip>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef long double LD;
typedef pair<LD, LD> PLDLD;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define CLR(a) memset((a), 0 ,sizeof(a))
#define ALL(a) a.begin(),a.end()

const double eps=1e-5;
const int INF=1e9;

int f[1000][1000];
int tbl[1001][1001];
int sum[1001][1001];
int main()
{
    int n;
    cin>>n;

    REP(j,n)
    REP(i,n)
    cin>>f[i][j];

    REP(i,n)
    {
        int cnt=0;
        FOR(j,i,n)
        {
            cnt+=f[i][j];
            sum[i][j]=cnt;
        }
    }

    REP(i,n)
    {
        int mx=tbl[i][i];
        FOR(j,i-1,n)
        {   
            if(j==-1)continue;
            mx=max(tbl[i][j],mx);
            tbl[i+1][j]=mx+sum[i][j];
            //cout<<i+1<<" "<<j<<" "<<tbl[i+1][j]<<endl;
        }
    }

    cout<<tbl[n][n-1]*2<<endl;
}

