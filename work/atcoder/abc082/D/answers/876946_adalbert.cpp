#include <bits/stdc++.h>
using namespace std;
#define y1 cgbngfgn
#define pb push_back
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fir first
#define m_p make_pair
#define sec second
#define files(name) freopen(name".dat","r",stdin); freopen (name".sol","w",stdout);
#pragma GCC optimize ("O3")
#pragma GCC optimize ("O2")
#define time pdojegoritg
typedef long long ll;
typedef long double ld;
const int arr=500000;

bool dp[9001][9001*4];

signed main()
{
    string st;
    cin>>st;
    int x,y;
    cin>>x>>y;
    vector<int> vec1,vec2;
    int now=1;
    int sum=0;

    for (auto i:st)
    {
        if (i=='T')
        {
            if (now)
                vec1.pb(sum); else
                vec2.pb(sum);
            now=!now;
            sum=0;
        } else
        {
            sum++;
        }
    }
    if (now)
        vec1.pb(sum); else
        vec2.pb(sum);


    int pl=st.size()+100;
    dp[1][vec1[0]+pl]=1;
    //cout<<dp[1][1+pl];
    for (int i=2;i<=vec1.size();i++)
        for (int j=-pl;j<=pl;j++)
        if (dp[i-1][j+pl])
        {
            dp[i][j+pl+vec1[i-1]]=1;
            dp[i][j+pl-vec1[i-1]]=1;
        }
    //cout<<dp[2][-2+pl]<<'\n';


    bool ch=dp[vec1.size()][x+pl];
    dp[0][pl]=1;
    for (int i=1;i<=vec1.size();i++)
        for (int j=-pl;j<=pl;j++)
            dp[i][j+pl]=0;

    for (int i=1;i<=vec2.size();i++)
        for (int j=-pl;j<=pl;j++)
        if (dp[i-1][j+pl])
        {
            dp[i][j+pl+vec2[i-1]]=1;
            dp[i][j+pl-vec2[i-1]]=1;
        }


    ch&=dp[vec2.size()][y+pl];

    if (ch)
        cout<<"Yes"<<'\n' ;else
        cout<<"No"<<'\n';
}
