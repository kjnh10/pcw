
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <list>
#include <time.h>
#include <math.h>
#include <random>
#include <deque>
#include <queue>
#include <cassert>
#include <iomanip>
 
using namespace std;
 
mt19937 Rand(16092002);
mt19937_64 BigRand(16092002);
 
typedef long long ll;
 
typedef long long ll;
 
struct edge
{
    int v, to;
    ll cap;
    edge(int a, int b, ll c)
    {
        v = a, to = b, cap = c;
    }
    edge() {}
};
 
const int N = 1e6 + 7;
 
vector <edge> e;
vector <int> g[N];
int us[N];
int usbs = 1;
int d[N];
int q[N];
int ded[N];
int ptr[N];
int after_bfs = 1;
int visb = 1;
ll ans = 0;
int qh, qt;
int s, t;
int l;
 
void add_edge(int u, int v, ll cap)
{
    g[u].push_back(e.size());
    e.push_back({u, v, cap});
    g[v].push_back(e.size());
    e.push_back({v, u, 0});
}
 
bool bfs()
{
    qh = qt = 0;
    us[s] = usbs;
    q[qt++] = s;
    d[s] = 0;
    while (qh < qt)
    {
        int v = q[qh++];
        for (auto c : g[v])
        {
            if (us[e[c].to] != usbs && e[c].cap >= l)
            {
                d[e[c].to] = d[v] + 1;
                us[e[c].to] = usbs;
                q[qt++] = e[c].to;
            }
        }
    }
    return (us[t] == usbs++);
}
 
int dfs(int v = s, ll c = 1e18)
{
    if (!c)
    {
        return 0;
    }
    if (v == t)
    {
        ans += c;
        return c;
    }
    if (ded[v] != after_bfs)
    {
        ded[v] = after_bfs;
        ptr[v] = 0;
    }
    for (; ptr[v] < (int) g[v].size(); ptr[v]++)
    {
        int ind = g[v][ptr[v]];
        if (e[ind].cap >= l && d[e[ind].to] == d[v] + 1)
        {
            ll x = dfs(e[ind].to, min(c, e[ind].cap));
            if (x)
            {
                e[ind].cap -= x;
                e[ind ^ 1].cap += x;
                return x;
            }
        }
    }
    return 0;
}
 
int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
#else
    ///freopen("flow2.in", "r", stdin);
    //freopen("flow2.out", "w", stdout);
#endif
    int n;
    scanf("%d", &n);
    vector <int> a(n + 1);
    ll res = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        if (a[i] > 0)
        {
            res += a[i];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (a[i] < 0)
        {
            for (int j = i; j <= n; j += i)
            {
                if (a[j] > 0)
                {
                    add_edge(i, j, 1e18);
                }
            }
        }
    }
    s = 0, t = n + 1;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] < 0) add_edge(s, i, -a[i]);
        else add_edge(i, t, a[i]);
    }
    l = (1 << 30);
    for (; l > 0; l /= 2)
    {
        while (bfs())
        {
            after_bfs++;
            while (dfs())
            {
                continue;
            }
        }
    }
    cout << res - ans << '\n';
}
