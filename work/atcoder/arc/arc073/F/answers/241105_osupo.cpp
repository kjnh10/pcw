#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cassert>
#include <cstring>
#include <vector>
#include <valarray>
#include <array>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <complex>
#include <random>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;
constexpr ll TEN(int n) { return (n==0) ? 1 : 10*TEN(n-1); }

int bsr(uint x) { return 31 - __builtin_clz(x); }
int bsr(ull x) { return 63 - __builtin_clzll(x); }
int bsf(uint x) { return __builtin_ctz(x); }
int bsf(ull x) { return __builtin_ctzll(x); }

template<class N>
struct SegTree {
    int lg, sz;
    vector<N> n;
    SegTree() {}
    SegTree(int sz) {
        assert(sz >= 1);
        lg = bsr(uint(2*sz-1));
        sz = 1<<lg;
        this->sz = sz;
        n = vector<N>(2*sz);
        for (int i = 2*sz-1; i >= sz; i--) {
            n[i] = N();
        }
        for (int i = sz-1; i >= 1; i--) {
            n[i] = N(n[2*i], n[2*i+1]);
        }
    }
    void all_update() {
        for (int i = 1; i <= sz-1; i++) {
            n[i].push();
        }
        for (int i = sz-1; i >= 1; i--) {
            n[i].update(n[2*i], n[2*i+1]);
        }
    }
    template<class Q>
    Q single(int idx, Q q) {
        if (idx < 0 || sz <= idx) return q;
        idx += sz;
        for (int i = lg; i >= 1; i--) {
            int k = idx>>i;
            n[k].push(n[2*k], n[2*k+1]);
        }
        q += n[idx];
        if (q.update()) {
            for (int i = 1; i <= lg; i++) {
                int k = idx>>i;
                n[k].update(n[2*k], n[2*k+1]);
            }
        }
        return q;
    }
    template<class Q>
    void query(int a, int b, Q &q, int k, int sz) {
        if (a <= 0 && sz <= b) {
            q += n[k];
            return;
        }
        n[k].push(n[2*k], n[2*k+1]);
        if (a < sz/2) query(a, b, q, 2*k, sz/2);
        if (sz/2 < b) query(a-sz/2, b-sz/2, q, 2*k+1, sz/2);
        if (q.update()) n[k].update(n[2*k], n[2*k+1]);
    }
    template<class Q>
    Q query(int a, int b, Q q) {
        if (a < sz && 0 < b) query(a, b, q, 1, sz);
        return q;
    }
    struct NodeQuery {
        N n;
        static constexpr bool update() { return false; }
        void operator+=(N &r) { N nn; nn.update(n, r); n = nn; }
    };
};

struct Node {
    ll mi;
    void init() {
        mi = TEN(18);
    }
    Node() { init(); } // leaf
    Node(Node &l, Node &r) { init(); update(l, r); }
    void update(const Node &l, const Node &r) {
        mi = min(l.mi, r.mi);
    }
    void push(Node &l, Node &r) {
    }
    // query
    struct MinQuery {
        ll mi = TEN(18);
        static constexpr bool update() { return false; }
        void operator+=(Node &r) { mi = min(mi, r.mi); }
    };
    struct SetQuery {
        ll x;
        static constexpr bool update() { return true; }
        void operator+=(Node &n) { n.mi = min(n.mi, x); }
    };
};

int n, q;
V<int> x;


int main() {
    int a, b;
    scanf("%d %d %d %d", &n, &q, &a, &b);
    a--; b--;
    q++;
    x = V<int>(q); x[0] = b;
    for (int i = 1; i < q; i++) {
        scanf("%d", &(x[i])); x[i]--;
    }
    SegTree<Node> ldp(n), rdp(n);
    for (int i = 0; i < n; i++) {
        ldp.single(i, Node::SetQuery{i});
    }
    ll base = 0;
    for (int i = q-1; i >= 1; i--) {
        ll dif = abs(x[i-1] - x[i]);
        ll dpx = min(
            ldp.query(x[i-1], n, Node::MinQuery{}).mi - x[i-1],
            rdp.query(0, x[i-1], Node::MinQuery{}).mi + x[i-1]);
        ll tar1 = dpx - dif + x[i];
        ll tar2 = dpx - dif - x[i];
        base += dif;
        ldp.single(x[i], Node::SetQuery{tar1});
        rdp.single(x[i], Node::SetQuery{tar2});
    }
    ll ans = base + min(
        ldp.query(a, n, Node::MinQuery{}).mi - a,
        rdp.query(0, a, Node::MinQuery{}).mi + a);
    printf("%lld\n", ans);
    return 0;
}
