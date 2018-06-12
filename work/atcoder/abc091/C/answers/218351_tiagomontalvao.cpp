#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define INF 0x3f3f3f3f

const int N = 1024;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

int n, m; 
vector<int> g1[N]; 
int pair_g1[N], pair_g2[N], dist[N]; 

bool bfs() { 
    queue<int> q; 
    for (int u = 1; u <= n; u++) { 
        dist[u] = INF; 
        if (pair_g1[u] == 0) { 
            dist[u] = 0; 
            q.push(u); 
        } 
    } 
    dist[0] = INF; 
    while (!q.empty()) { 
        int u = q.front(); q.pop(); 
        for (int i = 0; i < g1[u].size(); i++) { 
            int v = g1[u][i]; 
            if (dist[pair_g2[v]] == INF) { 
                dist[pair_g2[v]] = dist[u] + 1; 
                q.push(pair_g2[v]); 
            } 
        } 
    } 
    return dist[0] != INF; 
}

bool dfs(int u) { 
    if (u == 0) 
        return 1; 
    for (int i = 0; i < g1[u].size(); i++) { 
        int v = g1[u][i]; 
        if (dist[pair_g2[v]] == dist[u] + 1 && dfs(pair_g2[v])) { 
            pair_g1[u] = v; 
            pair_g2[v] = u; 
            return 1; 
        } 
    } 
    dist[u] = INF; 
    return 0;
}

int hk() { 
    memset(pair_g1, 0, sizeof(pair_g1)); 
    memset(pair_g2, 0, sizeof(pair_g2)); 
    int matching = 0; 
    while (bfs()) 
        for (int u = 1; u <= n; u++) 
            if (pair_g1[u] == 0 && dfs(u)) 
                matching++; 
    return matching; 
}

int main() {
    cin >> n;
    m = n;
    vii a(n+1), b(n+1);
    for (int i = 1; i <= n; ++i)
        cin >> a[i].st >> a[i].nd;
    for (int i = 1; i <= n; ++i)
        cin >> b[i].st >> b[i].nd;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (a[i].st < b[j].st and a[i].nd < b[j].nd) {
                g1[i].push_back(j+n);
            }
        }
    }
    printf("%d\n", hk());
    return 0;
}