#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using ull = unsigned long long;

const int MX = 707;

bool g[MX][MX];
bool rg[MX][MX];

int c[MX];
int cid[MX];

int dfs(int n, int v, int cc, int ccid) {
    c[v] = cc;
    cid[v] = ccid;
    for (int to = 1; to <= n; to++) {
        if (rg[v][to] && c[to] == 0) {
            dfs(n, to, 3 - cc, ccid);
        }
    }
}

int cnt[MX][3];

bool dp[MX][MX];

int main() {
#ifdef BZ
    freopen("in", "r", stdin);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i != j) {
                rg[i][j] = true;
            }
        }
    }

    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u][v] = g[v][u] = true;
        rg[u][v] = rg[v][u] = false;
    }

    int nv = 0;
    for (int i = 1; i <= n; i++) {
        if (c[i] == 0) {
            nv++;
            dfs(n, i, 1, nv);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (rg[i][j] && c[i] == c[j]) {
                cout << -1 << "\n";
                return 0;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cnt[cid[i]][c[i]]++;
    }

    dp[1][0] = true;
    for (int i = 1; i <= nv; i++) {
        for (int j = 0; j <= n; j++) {
            if (dp[i][j]) {
                dp[i + 1][j + cnt[i][1]] = true;
                dp[i + 1][j + cnt[i][2]] = true;
            }
        }
    }

    int ans = 1e9 + 7;
    for (int i = 0; i <= n; i++) {
        if (dp[nv + 1][i]) {
            int j = n - i;
            ans = min(ans, i * (i - 1) / 2 + j * (j - 1) / 2);
        }
    }

    cout << ans << "\n";

}
