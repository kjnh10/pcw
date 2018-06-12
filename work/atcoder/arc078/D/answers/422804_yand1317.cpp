#include <cstdio>
#include <vector>
static const int MAXN = 1e5 + 4;

int n;
std::vector<int> e[MAXN];

int par[MAXN], dep[MAXN], sts[MAXN];

void dfs(int u, int p = -1, int d = 0)
{
    par[u] = p;
    dep[u] = d;
    sts[u] = 1;
    for (int v : e[u]) if (v != p) {
        dfs(v, u, d + 1);
        sts[u] += sts[v];
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0, u, v; i < n - 1; ++i) {
        scanf("%d%d", &u, &v); --u, --v;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    dfs(0);
    int moves = (dep[n - 1] + 1) / 2;
    int v = n - 1;
    for (int i = 0; i < moves - 1; ++i) v = par[v];
    puts(n - sts[v] > sts[v] ? "Fennec" : "Snuke");

    return 0;
}
