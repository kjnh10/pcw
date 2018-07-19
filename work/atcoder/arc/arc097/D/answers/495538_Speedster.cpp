#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define fo(i, n) for(int i = 1; i <= n;++i)

typedef long long ll;

const int N = 302066;
const ll inf = 1e9;
int used[N];
set<int> s, t;
int a[N], n, m;
int u, v;
vector<int> g[N];

inline void dfs(int v) {
    used[v] = 1;
    s.insert(a[v]);
    t.insert(v);
    for(int to : g[v])
        if(!used[to])dfs(to);
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    fo(i, n) cin >> a[i];
    fo(i, m) {
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    int res = 0;
    fo(i, n) {

        if(!used[i]) {
            s.clear(); t.clear();
            dfs(i);
            for(int x : s) if(t.find(x) != t.end()) ++res;
        }

    }
    cout << res;
    return 0;
}