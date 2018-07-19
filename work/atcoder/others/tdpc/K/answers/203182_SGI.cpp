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
    vector<PII> p(n);
    REP(i,n)
    {
        int x,r;
        cin>>x>>r;
        p[i]=PII(x+r,x-r);
    }
    sort(ALL(p),greater<PII>());
    vector<int> leng(n+1,INF);
    leng[0]=-INF;
    int ans=0;
    REP(i,n)
    {
        int t=lower_bound(ALL(leng), p[i].second)-leng.begin();
        leng[t]=p[i].second;
        ans=max(ans,t);
    }
    

    cout<<ans<<endl;

}

