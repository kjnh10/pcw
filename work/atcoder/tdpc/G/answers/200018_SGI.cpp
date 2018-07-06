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
const LL INF=1e18*2;

int pt[10000000][26];
int main()
{
    string s;
    cin>>s;
    LL n=s.size();
    LL k;
    cin>>k;

    vector<int> p(26,-1);
    vector<LL> dp(n,1);
    for(int i=n-1;i>=0;i--)
    {
        REP(j,26)
        {
            pt[i][j]=p[j];
            if(p[j]==-1)    continue;
            //if(s[i]-'a'==j) continue;
            dp[i] += dp[p[j]];
            if(dp[i]>INF)dp[i]=INF;
        }
        p[s[i]-'a']=i;
    }

    LL kk=0;
    string ans="";
    int ind=-1;
    //bool flag=1;
    while(kk<k)
    {
        REP(i,26)
        {
            if(p[i]==-1)continue;
            if(kk+dp[p[i]]<k)
            {
                kk+=dp[p[i]];
            }
            else
            {
                ans+=(i+'a');
                kk++;
                ind=p[i];
                break;
            }
        }
        if(ind==-1)
        {
            //flag=0;
            ans="Eel";
            break;
        }

        REP(i,26)
        {
            p[i]=pt[ind][i];
        }
    }

    cout<<ans<<endl;
}

