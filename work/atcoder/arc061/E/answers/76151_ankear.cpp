#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <bitset>
#include <map>
#include <unordered_map>
#include <deque>
#include <queue>
#include <string>
#include <tuple>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <cassert>

#define pb push_back
#define pbk pop_back
#define sz(a) ((int) (a).size())
#define all(a) (a).begin(), (a).end()
#define mp make_pair
#define mt make_tuple
#define fs first
#define sc second
#define next hunext
#define prev huprev
#define rank hurank
#define hash huhash

#ifdef LOCAL42
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 42
#endif

using namespace std;

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int inf = int(1e9);
const ll linf = ll(1e18);
const double eps = 1e-9;
const double pi = 4 * atan(1.0);
const int N = int(1e6) + 100;

int d[N];
vector<pii> g[N], g2[N];
vi num[N], num2[N];
deque<int> q;

inline void add(int a, int b, int c) {
    g2[a].pb(mp(b, c));
}

int main() {
#ifdef LOCAL42
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        --a;
        --b;
        g[a].pb(mp(c, b));
        g[b].pb(mp(c, a));
    }
    if (sz(g[0]) == 0 || sz(g[n - 1]) == 0) {
        puts("-1");
        return 0;
    }
    int sz = 0;
    for (int i = 0; i < n; ++i) {
        sort(all(g[i]));
        num[i].resize(sz(g[i]));
        num2[i].resize(sz(g[i]));
        for (int j = 0; j < sz(g[i]); ++j) {
            num[i][j] = sz++;
            num2[i][j] = sz++;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < sz(g[i]); ++j) {
            add(num2[i][j], num[i][j], 0);
            int pos = lower_bound(all(g[g[i][j].sc]), mp(g[i][j].fs, i)) - g[g[i][j].sc].begin();
            assert(pos < sz(g[g[i][j].sc]) && g[g[i][j].sc][pos] == mp(g[i][j].fs, i));
            add(num2[i][j], num2[g[i][j].sc][pos], 0);
            add(num[i][j], num2[i][j], 1);
            if (j > 0) {
                add(num[i][j], num[i][j - 1], 0);
                if (g[i][j].fs == g[i][j - 1].fs) {
                    add(num2[i][j], num2[i][j - 1], 0);
                }
            }
            if (j + 1 < sz(g[i])) {
                add(num[i][j], num[i][j + 1], 0);
                if (g[i][j].fs == g[i][j + 1].fs) {
                    add(num2[i][j], num2[i][j + 1], 0);
                }
            }
        }
    }
    for (int i = 0; i < sz; ++i) {
        d[i] = inf;
    }
    d[num[0][0]] = 0;
    q.push_back(num[0][0]);
    while (!q.empty()) {
        int v = q.front();
        q.pop_front();
        for (pii e : g2[v]) {
            if (d[e.fs] > d[v] + e.sc) {
                d[e.fs] = d[v] + e.sc;
                if (e.sc == 0) {
                    q.push_front(e.fs);
                } else {
                    q.push_back(e.fs);
                }
            }
        }
    }
    if (d[num[n - 1][0]] == inf) {
        puts("-1");
    } else {
        cout << d[num[n - 1][0]] << endl;
    }
    return 0;
}
