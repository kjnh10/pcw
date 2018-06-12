
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
const int INF = 1000000001;
const ll LINF = 1000000000000000001LL;

/*************************************************************************/

const int N = 200004;
ll fact[N], revFact[N];

ll expo(ll a, ll n, ll mod) {
    ll ans = 1;

    while (n) {
        if (n & 1LL) ans = (ans * a) % mod;

        n >>= 1;
        a = (a * a) % mod;
    }

    return ans;
}

ll revMod(ll a, ll mod) {
    return expo(a, mod - 2, mod);
}

void pre() {
    fact[0] = revFact[0] = 1;
    FOR(i,1,N-1) {
        fact[i] = (i * fact[i-1]) % MOD;
        revFact[i] = revMod(fact[i], MOD);
    }
}

ll binom(int n, int m) {
    if (m > n) return 0;

    ll res = (fact[n] * revFact[n-m]) % MOD;
    res = (res * revFact[m]) % MOD;
    
    return res;
}

ll interleave(int n, int m) {
    return binom(n + m, n);
}

/*************************************************************************/

pii dfs(int v, int par, VVI &g) {
    ll ans = 1, sub = 0;
    
    for (int u : g[v]) if (u != par) {
        auto p = dfs(u, v, g);
        
        int uAns = p.st;
        int uSub = p.nd;
        
        ans = (ans * uAns) % MOD;
        ans = (ans * interleave(sub, uSub)) % MOD;
        
        sub += uSub;
    }
    
    sub++;
    
    return {(int) ans, sub};
}

int solveEdgeGraph(int n, VVI &edgeGraph) {
    return dfs(n-1, -1, edgeGraph).st;
}

int solveWithDir(int n, VI &dir, VVI &g) {
    map <pii,int> edgeId;
    int curr = 0;
    
    FOR(i,0,n-1) for (int j : g[i]) if (i < j) {
        edgeId[{i, j}] = curr++;
    }
    
    VVI edgeGraph(n+1);
    
    auto getEdgeId = [&](int i, int j) {
        auto p = minmax(i, j);
        return edgeId[p];
    };
    
    VB root(n, true);
    FOR(i,0,n-1) for (int j : g[i]) if (j < dir[i]) {
        int a = getEdgeId(i, j);
        int b = getEdgeId(i, dir[i]);
        
        edgeGraph[b].pb(a);
        root[a] = false;
    }
    
    FOR(i,0,n-1) if (root[i]) {
        edgeGraph[n].pb(i);
    }
    
    return solveEdgeGraph(n+1, edgeGraph);
}

int solve(int n, VVI &g) {
    VI deg(n);
    FOR(i,0,n-1) deg[i] = SIZE(g[i]);
    
    int edges = 0;
    FOR(i,0,n-1) edges += deg[i];
    
    if (edges / 2 != n) {
        return 0;
    }
    
    queue <int> q;
    FOR(i,0,n-1) if (deg[i] == 1) {
        q.push(i);
    }
    
    VB removed(n, false);
    VI dir(n,-1);
    
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        
        removed[v] = true;
        
        for (int u : g[v]) if (!removed[u]) {
            dir[v] = u;
            deg[u]--;
            
            if (deg[u] == 1) {
                q.push(u);
            }
            
            break;
        }
    }
    
    int v;
    FOR(i,0,n-1) if (!removed[i]) {
        v = i;
        break;
    }
    
    auto getNeigh = [&](int v, int otherThan) {
        for (int u : g[v]) if (!removed[u] && u != otherThan) {
            return u;
        }
        
        return -1;
    };
    
    VI cycle = {v};
    int prev = -1;
    
    while (true) {
        int next = getNeigh(v, prev);
        if (next == -1) break;
        
        cycle.pb(next);
        
        removed[v] = true;
        prev = v;
        v = next;
    }
    
    ll ans = 0;
    
    FOR(_,0,1) {
        FORE(i,cycle) {
            dir[cycle[i]] = cycle[(i + 1) % SIZE(cycle)];
        }
        
        ans = (ans + solveWithDir(n, dir, g)) % MOD;
        reverse(cycle.begin(), cycle.end());
    }
    
    return ans;
}

/*************************************************************************/

struct FAU {
    VI p, r;

    FAU(int n): p(n,-1), r(n,0) {}

    int find(int x) {
        if (p[x] == -1) return x;
        return p[x] = find(p[x]);
    }

    void join(int x, int y) {
        x = find(x); y = find(y);
        if (x == y) return ;

        if (r[x] > r[y]) p[y] = x;
        else p[x] = y;

        if (r[x] == r[y]) ++r[y];
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    pre();
    
    int n;
    cin >> n;
    
    int v = 2 * n;
    
    VVI g(v);
    FAU fau(v);
    
    FOR(_,1,v) {
        int x, y;
        cin >> x >> y; x--; y--;
        
        g[x].pb(n + y);
        g[n + y].pb(x);
        
        fau.join(x, n + y);
    }
    
    VVI comp(v);
    FOR(i,0,v-1) {
        comp[fau.find(i)].pb(i);
    }
    
    ll ans = 1;
    int currSize = 0;
    
    for (auto &c : comp) if (!c.empty()) {
        int m = SIZE(c);
        VVI shrG(m);
        
        for (int v : c) {
            int vId = lower_bound(c.begin(), c.end(), v) - c.begin();
            
            for (int u : g[v]) {
                int uId = lower_bound(c.begin(), c.end(), u) - c.begin();
                shrG[vId].pb(uId);
            }
        }
        
        ll here = solve(m, shrG);
        
        ans = (ans * here) % MOD;
        ans = (ans * interleave(currSize, m)) % MOD;
        
        currSize += m;
    }
    
    cout << ans;

    return 0;
}

/*************************************************************************/
