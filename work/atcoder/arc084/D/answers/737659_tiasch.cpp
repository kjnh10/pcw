#include <cstdio>
#include <climits>
#include <queue>

const int M = 100000;

int m, dist[M];

int main()
{
    scanf("%d", &m);
    for (int i = 0; i < m; ++ i) {
        dist[i] = INT_MAX;
    }
    std::priority_queue<std::pair<int, int>> pq;
    for (int i = 1; i < 10; ++ i) {
        if (dist[i % m] == INT_MAX) {
            dist[i % m] = i;
            pq.emplace(-i, i % m);
        }
    }
    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();
        if (-top.first == dist[top.second]) {
            for (int d = 0; d < 10; ++ d) {
                int r = (top.second * 10 + d) % m;
                if (-top.first + d < dist[r]) {
                    dist[r] = -top.first + d;
                    pq.emplace(-dist[r], r);
                }
            }
        }
    }
    printf("%d\n", dist[0]);
}
