#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <string>
#include <cstring>
#include <complex>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

const int INF = (int)1e9;
const int N = 15;
const int M = (1 << N) + 5;
int g[N][N];
int n;
int a[N][M];
int dp[2][M][N];

void read()
{
    int m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int v, u, w;
        scanf("%d%d%d", &v, &u, &w);
        v--;u--;
        g[v][u] = g[u][v] = w;
    }
}

void precalc()
{
    for (int mask = 0; mask < (1 << n); mask++) {
        for (int v = 0; v < n; v++) {
            if ((mask >> v) & 1) {
                a[v][mask] = INF;
                continue;
            }
            a[v][mask] = 0;
            for (int u = 0; u < n; u++) {
                if (((mask >> u) & 1) == 0) continue;
                a[v][mask] += g[v][u];
            }
        }
    }
}

void brute(int v, int our, int cost, int mask, int V) {
    if (v == n) {
        dp[0][mask | our][V] = min(dp[0][mask | our][V], cost);
        return;
    }
    brute(v + 1, our, cost, mask, V);
    if ((mask >> v) & 1) return;
    if (v == V) return;
    brute(v + 1, our | (1 << v), cost + a[v][mask], mask, V);
    return;
}

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    read();
    precalc();

    for (int mask = 0; mask < (1 << n); mask++)
        for (int v = 0; v < n; v++)
            dp[0][mask][v] = dp[1][mask][v] = INF;
    dp[1][0][0] = 0;

    for (int mask = 0; mask < (1 << n); mask++) {
        
        for (int v = 0; v < n; v++) {
            if (dp[0][mask][v] == INF) continue;
            for (int u = 0; u < n; u++) {
                if ((mask >> u) & 1) continue;
                if (g[v][u] == 0) continue;
                dp[1][mask][u] = min(dp[1][mask][u], dp[0][mask][v] + a[u][mask] - g[v][u]);
            }
        }

        for (int v = 0; v < n; v++) {
            if (dp[1][mask][v] == INF) continue;
            brute(0, 1 << v, dp[1][mask][v], mask, v);
        }

    }

    printf("%d\n", dp[0][(1 << n) - 1][n - 1]);

    return 0;
}