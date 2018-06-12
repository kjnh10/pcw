#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n==0) ? 1 : 10*TEN(n-1); }

template <class E>
using Graph = vector<vector<E>>;

template<class D, D INF>
struct Dijkstra {
    vector<D> res; //res[i] = sからiまでの最短距離
    
    template<class E>
    Dijkstra(const Graph<E> &g, int s) {
        int V = (int)g.size();
        res = vector<D>(V, INF);
        
        using P = pair<D, int>;
        priority_queue<P, vector<P>, greater<P>> q;
        q.push(P(0, s));
        res[s] = 0;
        while (!q.empty()) {
            P p = q.top(); q.pop();
            if (res[p.second] < p.first) continue;
            for (E e: g[p.second]) {
                if (p.first+e.dist < res[e.to]) {
                    res[e.to] = p.first+e.dist;
                    q.push(P(res[e.to], e.to));
                }
            }
        }
    }
};

struct Edge {
    int to;
    ll dist;
};

int main() {
    int n;
    cin >> n;
    Graph<Edge> g(n+1);
    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b; a--; b--;
        g[a].push_back(Edge{b, 1});
        g[b].push_back(Edge{a, 1});
    }
    vector<int> fix(n, -1);
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int v, p;
        cin >> v >> p; v--;
        fix[v] = p;
        g[n].push_back(Edge{v, p});
    }
    Dijkstra<ll, TEN(15)> da(g, n);
    for (int i = 0; i < n; i++) {
        int up = da.res[i];
        if (fix[i] != -1 && fix[i] != up) {
            printf("No\n");
            return 0;
        }
        fix[i] = up;
    }

    for (int i = 0; i < n; i++) {
        for (auto e: g[i]) {
            int j = e.to;
            if (abs(fix[i]-fix[j]) != 1) {
                printf("No\n");
                return 0;
            }
        }
    }

    printf("Yes\n");
    for (int i = 0; i < n; i++) {
        printf("%d\n", fix[i]);
    }
    return 0;
}