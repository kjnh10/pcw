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

struct Node {
    using NP = Node*;
    NP l, r;
    int sz, mi;
    Node(int sz) : sz(sz), l(nullptr), r(nullptr) {
        mi = TEN(9);
        if (sz == 1) return;
        l = new Node(sz/2);
        r = new Node(sz-sz/2);
    }
    void set(int k, int x) {
        if (sz == 1) {
            mi = min(mi, x);
            return;
        }
        if (k < sz/2) {
            l->set(k, x);
        } else {
            r->set(k-sz/2, x);
        }
        mi = min(l->mi, r->mi);
    }

    int get(int a, int b) {
        if (b <= 0 || sz <= a) return TEN(9);
        if (a <= 0 && sz <= b) return mi;
        return min(l->get(a, b), r->get(a-sz/2, b-sz/2));
    }
};

int main() {
    int off = 0;
    int n;
    scanf("%d", &n);
    V<int> b(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &(b[i]));
        if (!b[i]) {
            b[i]--;
            off++;
        }
    }
    VV<int> g(n+1);
    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        int x, y;
        scanf("%d %d", &x, &y); x--;
        g[x].push_back(y);
    }
    Node* tr = new Node(n+10);
    for (int i = 0; i <= n; i++) {
        if (i) {
            tr->set(i, tr->get(i-1, i) + b[i-1]);
        } else {
            tr->set(0, 0);
        }
        for (int d: g[i]) {
            tr->set(d, tr->get(i, d));
        }
    }
    printf("%d\n", off + tr->get(n, n+1));
    return 0;
}
