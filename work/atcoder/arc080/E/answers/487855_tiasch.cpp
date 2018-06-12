#include <algorithm>
#include <cstdio>
#include <climits>
#include <queue>
#include <vector>
#include <utility>

const int N = 200000;

int n, a[N];
std::pair<int, int> mi[N << 1][2];

int get_id(int l, int r)
{
    return l + r | l != r;
}

void build(int l, int r)
{
    int id = get_id(l, r);
    if (l == r) {
        mi[id][0] = mi[id][1] = {INT_MAX, -1};
        mi[id][l & 1] = {a[l], l};
    } else {
        int m = l + r >> 1;
        build(l, m);
        build(m + 1, r);
        mi[id][0] = std::min(mi[get_id(l, m)][0], mi[get_id(m + 1, r)][0]);
        mi[id][1] = std::min(mi[get_id(l, m)][1], mi[get_id(m + 1, r)][1]);
    }
}

std::pair<int, int> query(int l, int r, int a, int b, int t)
{
    if (b < l || r < a) {
        return {INT_MAX, -1};
    }
    if (a <= l && r <= b) {
        return mi[get_id(l, r)][t];
    }
    int m = l + r >> 1;
    return std::min(query(l, m, a, b, t), query(m + 1, r, a, b, t));
}

struct Sum
{
    Sum(int l, int r)
        : l(l), r(r)
    {
        auto x = query(0, n - 1, l, r - 1, l & 1);
        auto y = query(0, n - 1, x.second + 1, r, (l & 1) ^ 1);
        i = x.second, j = y.second;
        k = std::make_pair(x.first, y.first);
    }

    int l, r, i, j;
    std::pair<int, int> k;
};

bool operator < (const Sum& a, const Sum& b)
{
    return a.k > b.k;
}

int main()
{
#ifdef LOCAL_JUDGE
    freopen("E.in", "r", stdin);
#endif
    while (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; ++ i) {
            scanf("%d", a + i);
        }
        build(0, n - 1);
        std::priority_queue<Sum> heap;
        heap.push(Sum(0, n - 1));
        std::vector<int> result;
        while (!heap.empty()) {
            auto t = heap.top();
            heap.pop();
            result.push_back(t.k.first);
            result.push_back(t.k.second);
            if (t.l < t.i) {
                heap.push(Sum(t.l, t.i - 1));
            }
            if (t.i + 1 < t.j) {
                heap.push(Sum(t.i + 1, t.j - 1));
            }
            if (t.j < t.r) {
                heap.push(Sum(t.j + 1, t.r));
            }
        }
        for (int i = 0; i < n; ++ i) {
            printf("%d%c", result[i], " \n"[i == n - 1]);
        }
    }
}