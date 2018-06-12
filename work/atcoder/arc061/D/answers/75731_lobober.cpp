#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;

const int N = 100500;

set<pair<int, int>> pts;

set<pair<int, int>> inter;

typedef long long llong;

llong cnt[10];

int main() {
    int h, w, n;
    scanf("%d %d %d", &h, &w, &n);
    for (int i = 0; i < n; i++) {
        int x, y;
        scanf("%d %d", &y, &x);
        pts.insert(make_pair(x, y));
        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                inter.insert(make_pair(x + dx, y + dy));
            }
        }
    }
    for (auto pr : inter) {
        int x = pr.first;
        int y = pr.second;
        if (x <= 1 || y <= 1 || x >= w || y >= h)
            continue;
        int c = 0;
        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                c += pts.count(make_pair(x + dx, y + dy));
            }
        }
        if (c != 0)
            cnt[c]++;
    }
    cnt[0] = (h - 2) * 1ll * (w - 2) - accumulate(cnt + 1, cnt + 10, 0ll);
    for (int i = 0; i < 10; i++) {
        printf("%lld\n", cnt[i]);
    }
}
