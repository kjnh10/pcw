#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

const int N = 100000;

int a[N], t[N], result[N];

int main()
{
#ifdef LOCAL_JUDGE
    freopen("E.in", "r", stdin);
#endif
    int x, n, q;
    while (scanf("%d%d", &x, &n) == 2) {
        std::vector<std::pair<int, int>> events;
        for (int i = 0, turn; i < n; ++ i) {
            scanf("%d", &turn);
            events.emplace_back(turn, -1);
        }
        int q;
        scanf("%d", &q);
        for (int i = 0; i < q; ++ i) {
            scanf("%d%d", t + i, a + i);
            events.emplace_back(t[i], i);
        }
        std::sort(events.begin(), events.end());
        int dir = -1, i = 0, j = x, yi = 0, yj = x, t0 = 0;
        for (auto&& event : events) {
            int t = event.first;
            if (t0 < t) {
                int dt = t - t0;
                if (dir == -1) {
                    if (yi >= dt) {
                        yi -= dt;
                        yj -= dt;
                    } else if (yj < dt) {
                        i = j = yi = yj = 0;
                    } else {
                        i += dt - yi;
                        yi = 0;
                        yj -= dt;
                    }
                } else {
                    if (yj + dt <= x) {
                        yi += dt;
                        yj += dt;
                    } else if (yi + dt > x) {
                        i = j = 0;
                        yi = yj = x;
                    } else {
                        j -= yj - (x - dt);
                        yj = x;
                        yi += dt;
                    }
                }
            }
            t0 = t;
            int id = event.second;
            if (~id) {
                if (a[id] < i) {
                    result[id] = yi;
                } else if (a[id] > j) {
                    result[id] = yj;
                } else {
                    result[id] = yi + (a[id] - i);
                }
            } else {
                dir *= -1;
            }
        }
        for (int i = 0; i < q; ++ i) {
            printf("%d\n", result[i]);
        }
    }
}