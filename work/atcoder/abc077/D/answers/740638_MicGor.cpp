#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair < int, int > PII;
typedef pair < LL, LL > PLL;
typedef pair < LD, LD > PDD;

#define _upgrade ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
template < typename _T > inline void _DBG(const char *s, _T x) { cerr << s << " = " << x << "\n"; }
template < typename _T, typename... args > void _DBG(const char *s, _T x, args... a) { while(*s != ',') cerr << *s++; cerr << " = " << x << ','; _DBG(s + 1, a...); }

#ifdef LOCAL
#define DBG(...) _DBG(#__VA_ARGS__, __VA_ARGS__)
#else
#define DBG(...) (__VA_ARGS__)
#define cerr if(0) cout
#endif

// ********************** CODE ********************** //

const int N = 1e5 + 7;

bool vis[N][100];

int suma(int n)
{
    int res = 0;
    while(n > 0)
    {
        res += n % 10;
        n /= 10;
    }
    return res;
}

int n;

void dfs(int r, int s)
{
    if(s >= 99) return;
    if(vis[r][s]) return;
    vis[r][s] = 1;
    for(int i = 0; i < 10; i++)
        dfs((10 * r + i) % n, s + i);
}

int main()
{
    _upgrade
    cin >> n;
    for(int i = 0; i < n; i++)
        dfs(i, suma(i));
    //while(n % 2 == 0) n /= 2;
    //while(n % 5 == 0) n /= 5;
    int res = 1e9;
    for(int i = 1; i < 99; i++)
        if(vis[0][i]) res = min(res, i);
    cout << res << "\n";
    return 0;
}
