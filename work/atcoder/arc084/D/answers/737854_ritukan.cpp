#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int MX = 100 * 1000 + 7;
const int INF = 1000 * 1000 * 1000 + 7;
vector<pair<int, int> > g[MX];
int dist[MX];
int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 10; j++) {
            g[i].emplace_back((10 * i + j) % n, j);
        }
    }
    for (int j = 1; j < 10; j++) {
        g[n].emplace_back(j % n, j);
    }
    for (int i = 0; i <= n; i++) {
        dist[i] = INF;
    }
    dist[n] = 0;
    set<pair<int, int> > heap;
    for (int i = 0; i <= n; i++) {
        heap.emplace(dist[i], i);
    }
    while (!heap.empty()) {
        int v = (*heap.begin()).second;
        heap.erase(heap.begin());
        for (auto to : g[v]) {
            if (dist[to.first] > dist[v] + to.second) {
                heap.erase({dist[to.first], to.first});
                dist[to.first] = dist[v] + to.second;
                heap.emplace(dist[to.first], to.first);
            }
        }
    }
    printf("%d\n", dist[0]);
}

