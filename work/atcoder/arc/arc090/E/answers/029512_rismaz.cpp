
#include <bits/stdc++.h>

#define FOR(i,b,e) for(int i=(b); i <= (e); ++i)
#define FORD(i,b,e) for(int i=(b); i >= (e); --i)
#define SIZE(c) (int) (c).size()
#define FORE(i,c) FOR(i,0,SIZE(c)-1)
#define FORDE(i,c) FORD(i,SIZE(c)-1,0)

#define pb push_back
#define mp make_pair
#define st first
#define nd second


using namespace std;

typedef long long ll;
typedef pair <int,int> pii;
typedef pair <ll,ll> pll;

typedef vector <int> VI;
typedef vector <bool> VB;
typedef vector <pii> VP;
typedef vector <ll> VL;
typedef vector <pll> VPL;

typedef vector <VI> VVI;
typedef vector <VL> VVL;
typedef vector <VB> VVB;
typedef vector <VP> VVP;

const int MOD = 1000000007;

typedef ll dist_t;
const dist_t INF = 1LL << 60;

vector <dist_t> dijkstra(int src, VVP &g) {
    int n = SIZE(g);
    vector <dist_t> dist(n, INF);

    dist[src] = 0;
    
    priority_queue <pair<dist_t,int>> q;
    q.push({0, src});
    
    while (!q.empty()) {
        auto e = q.top(); q.pop();
        int v = e.nd;
        
        if (e.st != -dist[v]) continue;
        
        for (auto &e : g[v]) {
            int u = e.st;
            
            if (dist[u] > dist[v] + e.nd) {
                dist[u] = dist[v] + e.nd;
                q.push({-dist[u], u});
            }
        }
    }
    
    return dist;
}

int cnt(int v, VVI &gRev, VI &ans) {
    if (ans[v] == -1) {
        ans[v] = 0;
        for (int u : gRev[v]) {
            ans[v] = (ans[v] + cnt(u, gRev, ans)) % MOD;
        }
    }
    
    return ans[v];
}

VI countPaths(int src, VVI &gRev) {
    VI ans(gRev.size(), -1);
    ans[src] = 1;
    
    FORE(i,gRev) {
        cnt(i, gRev, ans);
    }
    
    return ans;
}

/*************************************************************************/

int main() {
    ios_base::sync_with_stdio(0);
    
    int n, m;
    cin >> n >> m;
    
    int s, t;
    cin >> s >> t; s--; t--;
    
    VVP g(n);
    while (m--) {
        int u, v, len;
        cin >> u >> v >> len; u--; v--;
        
        g[u].pb({v, len});
        g[v].pb({u, len});
    }
    
    auto dist = dijkstra(s, g);
    
    VVI sDag(n), tDag(n);
    FOR(i,0,n-1) for (auto &e : g[i]) {
        int j, len;
        tie(j, len) = e;
        
        if (dist[j] == dist[i] + len) {
            sDag[i].pb(j);
            tDag[j].pb(i);
        }
    }
    
    auto sPaths = countPaths(s, tDag);
    auto tPaths = countPaths(t, sDag);
    
    ll ans = ((ll) sPaths[t] * sPaths[t]) % MOD;
    ll whole = dist[t];
    
    FOR(i,0,n-1) if (2 * dist[i] == whole) {
        ll left = ((ll) sPaths[i] * sPaths[i]) % MOD;
        ll right = ((ll) tPaths[i] * tPaths[i]) % MOD;
        ll here = (left * right) % MOD;
        
        ans = (ans + MOD - here) % MOD;
    }
    
    FOR(i,0,n-1) for (int j : sDag[i]) {
        if (2 * dist[i] < whole && 2 * dist[j] > whole) {
            ll left = ((ll) sPaths[i] * sPaths[i]) % MOD;
            ll right = ((ll) tPaths[j] * tPaths[j]) % MOD;
            ll here = (left * right) % MOD;
            
            ans = (ans + MOD - here) % MOD;
        }
    }
    
    cout << ans;

    return 0;
}

/*************************************************************************/
