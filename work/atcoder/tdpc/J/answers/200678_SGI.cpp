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
const LL INF=1e9;

int main()
{
    int n;
    cin>>n;
    vector<int> x(n),ix(16);
    REP(i,n)
        cin>>x[i];
    
    sort(ALL(x));
    REP(i,n)
        ix[x[i]]=i;
    vector<LD> dp(1<<n,INF);
    dp[0]=0;
    function<LD(int)> dfs=[&](int p)
    {
        if(dp[p]!=INF)
            return dp[p];
        LD m=INF;
        bool b[16];
        REP(i,16)
            b[i]=0;
        REP(i,n)
        {
            if((p&(1<<i))>0)
            {
                b[x[i]]=1;
            }
        }
        int ind=0;
        FOR(i,1,15)
        {
            LD e=0;
            int cnt=0;
            for(int j=-1;j<2;j++)
            {
                if(b[i+j])
                {
                    e+=dfs(p-(1<<(ix[i+j])));
                    cnt++;
                }
            }
            if(cnt==3)
            {
                e/=3;
                e+=1;
            }
            else if(cnt==2)
            {
                e/=2;
                e+=1.5;
            }
            else if(cnt==1)
            {
                //e/=3;
                e+=3;
            }
            else
                e=INF;

            if(m>e)
            {
                m=e;
                ind=i;
            }
            /*if(e>0)
            cout<<p<<" "<<i<<":"<<e<<endl;*/
        }
        //cout<<p<<":"<<ind<<" "<<m<<endl;
        dp[p]=m;
        return m;
    };

    cout<<setprecision(10)<<fixed<<dfs((1<<(n))-1)<<endl;
}

