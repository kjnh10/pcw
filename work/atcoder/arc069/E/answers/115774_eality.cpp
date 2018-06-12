/// e.cpp

# include <stdio.h>
# include <bits/stdc++.h>
using namespace std;
const pair < int , int > DD[] = {{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}};
# define fi cin
# define fo cout
# define x first
# define y second
# define ll long long
# define IOS ios_base :: sync_with_stdio(0);cin.tie(0)
# define p(v) cerr << #v << " = " << v << '\n'
# define p2(v) cerr << #v << " = " << (complex < __typeof(v.x) > (v.x,v.y)) << '\n'
# define vi vector < int >
# define vl vector < ll >
# define pll pair < ll , ll >
# define pii pair < int , int >
# define mp make_pair
# define db long double
# define fail puts("-1")
# define yes puts("YES")
# define no puts("NO")
# define PP puts("Possible")
# define II puts("Impossible")
# define vii vector < pii >
# define vll vector < ll >
# define pb push_back
# define pdd pair < db , db >
template < class T > T smin(T &a,T b) {if (a > b) a = b;return a;}
template < class T > T smax(T &a,T b) {if (a < b) a = b;return a;}
int main(void)
{
    #ifdef CF
    freopen("input","r",stdin);
    #endif // CF
    srand(time(0));
    fo << fixed << setprecision(7);
    cerr << fixed << setprecision(7);
    int n;
    fi>>n;
    static ll ans[1 << 20];
    vector < pii > s;
    for (int i = 1;i <= n;++i)
    {
        int v;
        fi>>v;
        s.pb(mp(v,i));
    }
    sort(s.begin(),s.end(),[&](pii a,pii b)
         {
            if (a.x != b.x)
                return a.x > b.x;
            return a.y < b.y;
         });
    int mn = s[0].y;
    int was = s[0].x;
    int cur = 0;
    for (auto it : s)
    {
        ans[mn] += 1ll * cur * (was - it.x);
        smin(mn,it.y);
        was = it.x;
        ++cur;
    }
    ans[mn] += 1ll * cur * was;
    for (int i = 1;i <= n;++i)
        fo << ans[i] << '\n';
    cerr << "Time elapsed :" << clock() * 1000.0 / CLOCKS_PER_SEC << " ms" << '\n';
    return 0;
}
