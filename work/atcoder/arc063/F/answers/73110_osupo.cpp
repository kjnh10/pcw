#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <tuple>

using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n==0) ? 1 : 10*TEN(n-1); }

int bsr(int x) { return 31 - __builtin_clz(x); }

using P = pair<ll, ll>;
const int MN = 300300;

ll w, h;
int n;
P p[MN];

void trans() {
    swap(w, h);
    for (int i = 0; i < n; i++) {
        swap(p[i].first, p[i].second);
    }
    sort(p, p+n);
}


template<class N>
struct SegTree {
    int lg, sz;
    vector<N> n;
    SegTree(int sz) {
        lg = bsr(2*sz-1);
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
    template<class Q>
    Q single(int idx, Q q) {
        if (idx < 0 or sz <= idx) return q;
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
        if (a <= 0 and sz <= b) {
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
        if (a < sz and 0 < b) query(a, b, q, 1, sz);
        return q;
    }
};

struct Node {
    ll ma, lz;
    void init() {
        ma = lz = 0;
    }
    Node() { init(); }
    Node(Node &l, Node &r) { init(); update(l, r); }
    void update(const Node &l, const Node &r) {
        ma = max(l.ma, r.ma);
    }
    void push(Node &l, Node &r) {
        if (lz) {
            l.lzdata(lz);
            r.lzdata(lz);
            lz = 0;
        }
    }
    void lzdata(ll x) {
        ma += x; lz += x;
    }
    // query
    struct MaxQuery {
        ll ma = -TEN(18);
        static constexpr bool update() { return false; }
        void operator+=(Node &r) { ma = max(ma, r.ma); }
    };
    struct AddQuery {
        ll x;
        static constexpr bool update() { return true; }
        void operator+=(Node &n) { n.lzdata(x); }
    };
};

using T = array<ll, 3>;
ll calc(int a, int b) {
    if (b-a <= 1) return 0;
    int md = (a+b+1)/2;
    //a,a+1,...,md-1
    //md,...,b-1

    ll offw = p[md-1].first, offh = h/2;
    vector<T> vl, vr;
    ll dow, up;
    
    dow = 0; up = h;
    for (int i = md-1; i >= a; i--) {
        vl.push_back(T{offw-p[i].first, offh-dow, up-offh});
        if (p[i].second <= offh) {
            dow = max(dow, p[i].second);
        } else {
            up = min(up, p[i].second);
        }
    }

    vector<ll> c1, c2;

    dow = 0; up = h;
    for (int i = md; i < b; i++) {
        vr.push_back(T{p[i].first-offw, offh-dow, up-offh});
        c1.push_back(-(offh-dow));
        c2.push_back(-(up-offh));
        if (p[i].second <= offh) {
            dow = max(dow, p[i].second);
        } else {
            up = min(up, p[i].second);
        }
    }

    int M = b-md;
    vector<ll> ssv(M+1);
    SegTree<Node> sb(M), bs(M);
    ssv[M] = 0;
    for (int i = M-1; i >= 0; i--) {
        T tr = vr[i];
        ssv[i] = max(tr[0] + tr[1] + tr[2], ssv[i+1]);
        sb.single(i, Node::AddQuery{tr[0]+tr[1]});
        bs.single(i, Node::AddQuery{tr[0]+tr[2]});
    }
/*    printf("debug %d %d\n", a, b);
    for (auto tl: vl) {
        printf("%lld %lld %lld\n", tl[0], tl[1], tl[2]);
    }
    for (auto tl: vr) {
        printf("%lld %lld %lld\n", tl[0], tl[1], tl[2]);
    }*/
    ll ans = 0;
    for (auto tl: vl) {
/*        for (auto tr: vr) {
            ans = max(ans, tl[0]+tr[0] + min(tl[1], tr[1]) + min(tl[2], tr[2]));
        }*/
        int id1 = upper_bound(c1.begin(), c1.end(), -tl[1]) - c1.begin();
        int id2 = upper_bound(c2.begin(), c2.end(), -tl[2]) - c2.begin();
        {
            //big big
            int idx = min(id1, id2)-1;
            if (idx >= 0) {
                T tr = vr[idx];
                ans = max(ans, tl[0]+tr[0] + min(tl[1], tr[1]) + min(tl[2], tr[2]));
            }
        }
        {
            //small small
            int idx = max(id1, id2);
            ans = max(ans, tl[0]+ssv[idx]);
        }
        if (id1 > id2) {
            ans = max(ans, tl[0]+tl[1]+bs.query(id2, id1, Node::MaxQuery{}).ma);
        }
        if (id1 < id2) {
            ans = max(ans, tl[0]+tl[2]+sb.query(id1, id2, Node::MaxQuery{}).ma);
        }
    }
    ans = max(ans, calc(a, md));
    ans = max(ans, calc(md, b));
    return ans;
}


ll solve() {
    return calc(0, n);
}


int main() {
    cin >> w >> h >> n;
    p[0] = P(0, 0);
    for (int i = 1; i <= n; i++) {
        cin >> p[i].first >> p[i].second;
    }
    p[n+1] = P(w, h);
    n += 2;
    sort(p, p+n);
    ll ans = 0;
    ans = max(ans, solve());
    trans();
    ans = max(ans, solve());

    printf("%lld\n", 2*ans);

    return 0;
}