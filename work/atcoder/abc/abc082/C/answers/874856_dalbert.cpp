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
short int dp[5010][5010];
signed main()
{
    int n;
    cin>>n;
    map<int,int> mp;
    for (int i=1;i<=n;i++)
    {
        int a;
        cin>>a;
        mp[a]++;
    }

    int res=0;
    for (auto i:mp)
    {
        if (i.sec>=i.fir)
            res+=i.fir;
    }

    cout<<n-res;
}
