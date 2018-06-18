#include<bits/stdc++.h>
using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pl;

#define sl(x) scanf("%lld",&x)
#define pl(x) printf("%lld\n",x)
#define sz(x) ((int)x.size())
#define s(x) sort(x.begin(),x.end())
#define all(v) v.begin(),v.end()
#define rs(v) { s(v) ; r(v) ; }
#define r(v) {reverse(all(v));}
#define pb push_back
#define F first
#define S second
#define f(i,n) for(ll i=0;i<n;i++)
#define rep(i,a,b) for(int i=a;i<=b;i++)

const ll mod = 1000000007;
const ll inf = (ll)5e16;
const ld eps = 1e-12;
const ll N = 1000005;
const ll LOGN = 19;
const ld PI = 3.14159265358979323846;
ll mul(ll a, ll b, ll m = mod) { return (ll)(a * b) % m;}
ll add(ll a, ll b, ll m = mod) { a += b; if(a >= m) a -= m; if(a < 0) a += m; return a;}
ll power(ll a, ll b, ll m = mod) { if(b == 0) return 1; if(b == 1) return (a % m); ll x = power(a, b / 2, m); x = mul(x, x, m); if(b % 2) x = mul(x, a, m); return x;}
ll n, m, dist[N], vis[N];
vector < pl > g[N];
void dijkstra(ll s)
{
    f(i, n + 1) vis[i] = 0, dist[i] = inf;
    dist[s] = 0;
    priority_queue < pl > q;
    q.push({0, s});
    while(!q.empty())
    {
        ll u = q.top().S;
        q.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        for(pl x : g[u])
        {
            ll v = x.F;
            ll w = x.S;
            if(dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                q.push({-dist[v], v});
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    f(i, m)
    {
        ll a, b;
        cin >> a >> b;
        g[a].pb({b, 1});
        g[b].pb({a, 1});
    }
    dijkstra(1);
    if(dist[n] == 2)
    {
        cout << "POSSIBLE\n";
    }
    else
    {
        cout << "IMPOSSIBLE\n";
    }
    return 0;
}
