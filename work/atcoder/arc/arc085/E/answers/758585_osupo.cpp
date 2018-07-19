#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <numeric>
#include <random>
#include <vector>
#include <array>
#include <bitset>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n==0) ? 1 : 10*TEN(n-1); }
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;

/**
 * Edge Sample
 * ---
 * void add_edge(Graph<Edge> &g, int from, int to, int cap) {
 *     g[from].push_back(Edge{to, cap, (int)g[to].size()});
 *     g[to].push_back(Edge{from, 0, (int)g[from].size()-1});
 * }
 * ---
 */

template<class C>
struct MaxFlow {
    C flow;
    V<bool> dual;
};

template<class C, C EPS, class E>
struct MF_EXEC {
    static const C INF = numeric_limits<C>::max();
    VV<E> &g;
    int s, t;
    int N;
    V<int> level, iter;

    MaxFlow<C> info;
    MF_EXEC(VV<E> &g, int s, int t): g(g), s(s), t(t) {
        N = int(g.size());
        level = V<int>(N);
        iter = V<int>(N);

        C flow = 0;
        while (true) {
            bfs();
            if (level[t] < 0) break;
            fill(begin(iter), end(iter), 0);
            while (true) {
                C f = dfs(s, INF);
                if (!f) break;
                flow += f;
            }
        }
        V<bool> dual(N);
        for (int i = 0; i < N; i++) {
            dual[i] = level[i] == -1;
        }
        info = MaxFlow<C>{flow, dual};
    }

    void bfs() {
        queue<int> que;
        fill(begin(level), end(level), -1);
        level[s] = 0;
        que.push(s);
        while (!que.empty()) {
            int v = que.front(); que.pop();
            for (E e: g[v]) {
                if (e.cap <= EPS) continue;
                if (level[e.to] < 0) {
                    level[e.to] = level[v] + 1;
                    que.push(e.to);
                }
            }
        }
    }

    C dfs(int v, C f) {
        if (v == t) return f;
        for (int &i = iter[v]; i < int(g[v].size()); i++) {
            E &e = g[v][i];
            if (e.cap <= EPS) continue;
            if (level[v] < level[e.to]) {
                C d = dfs(e.to, min(f, e.cap));
                if (d <= EPS) continue;
                e.cap -= d;
                g[e.to][e.rev].cap += d;
                return d;
            }
        }
        return 0;
    }
};

template<class C, C EPS, class E>
MaxFlow<C> max_flow(VV<E> &g, int s, int t) {
    return MF_EXEC<C, EPS, E>(g, s, t).info;
}


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);

    struct E {
        int to; ll cap; int rev;
    };
    int n;
    cin >> n;
    int sv = n+1, tv = n+2;
    VV<E> g(n+3);
    auto add_edge = [&](int from, int to, ll cap) {
        g[from].push_back(E{to, cap, int(g[to].size())});
        g[to].push_back(E{from, 0, int(g[from].size())-1});
    };
    //s:叩き割る t:叩き割らない

    ll off = 0;
    for (int i = 1; i <= n; i++) {
        ll a;
        cin >> a;
        if (a < 0) {
            add_edge(sv, i, -a);
        } else {
            off += a;
            add_edge(i, tv, a);
        }
        for (int j = 2*i; j <= n; j += i) {
            add_edge(i, j, TEN(15));
        }
    }
    cout << off - max_flow<ll, 0>(g, sv, tv).flow << endl;
    return 0;
}
