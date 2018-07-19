#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 1 << 18;

int n;
vector<int> e[MAXN];
int cnt[MAXN];
vector<int> vct;
int frst;

void dfs(int v, int pr) {
    cnt[v] = 1;
    vct.push_back(v);

    if (v == n - 1) {
        frst = vct[((int)vct.size() + 1) / 2];
    }
    for (int to : e[v]) {
        if (to == pr) continue;
        dfs(to, v);
        cnt[v] += cnt[to];
    }
    vct.pop_back();
}

int main() {
#ifdef HOME
    assert(freopen("in", "r", stdin));
#endif


    while (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) {
            e[i].clear();
        }
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            --u; --v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        frst = -1;
        dfs(0, 0);
        bool win = cnt[frst] * 2 < n;
        string ans = win ? "Fennec" : "Snuke";
        cout << ans << endl;
    }


#ifdef HOME
    cerr << "time: " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
#endif
    return 0;
}