#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> P;

#define EACH(i,a) for (auto& i : a)
#define FOR(i,a,b) for (ll i=(a);i<(b);i++)
#define RFOR(i,a,b) for (ll i=(b)-1;i>=(a);i--)
#define REP(i,n) for (ll i=0;i<(n);i++)
#define RREP(i,n) for (ll i=(n)-1;i>=0;i--)
#define debug(x) cout<<#x<<": "<<x<<endl
#define pb push_back
#define ALL(a) (a).begin(),(a).end()

const ll linf = 1e18;
const int inf = 1e9;
const double eps = 1e-12;
const double pi = acos(-1);

template<typename T>
istream& operator>>(istream& is, vector<T>& vec) {
    EACH(x,vec) is >> x;
    return is;
}
template<typename T>
ostream& operator<<(ostream& os, vector<T>& vec) {
    REP(i,vec.size()) {
        if (i) os << " ";
        os << vec[i];
    }
    return os;
}
template<typename T>
ostream& operator<<(ostream& os, vector< vector<T> >& vec) {
    REP(i,vec.size()) {
        if (i) os << endl;
        os << vec[i];
    }
    return os;
}

// SegmentTree<int> seg(n, 0x7FFFFFFF, [](int a, int b){return min(a, b);});
template <typename T>
class SegmentTree {
    using func_t = function<T(T, T)>;
    const int n;
    const T id;
    func_t merge;
    vector<T> data;
    T sub(int l, int r, int node, int lb, int ub) {
        if (ub <= l || r <= lb) return id;
        if (l <= lb && ub <= r) return data[node];
        T vl = sub(l, r, node * 2 + 0, lb, (lb + ub) / 2);
        T vr = sub(l, r, node * 2 + 1, (lb + ub) / 2, ub);
        return merge(vl, vr);
    }
    int size(int n) {
            int res;
            for (res = 1; res < n; res <<= 1);
            return res;
    }
public:
    SegmentTree(int n, T id, func_t merge) :
        n(size(n)), id(id), merge(merge), data(size(n) * 2, id) {}
    void update(int p, T val) {
        assert (0 <= p && p < n);
        p += n;
        data[p] = val;
        while (p /= 2) {
            int l = p * 2, r = p * 2 + 1;
            data[p] = merge(data[l], data[r]);
        }
    }
    T find(int l, int r) {
        return sub(l, r, 1, 0, n);
    }
};

const ll mod = 1e9+7;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    ll n, m; cin >> n >> m;
    // assert(n <= 5000); // 部分点
    vector<ll> A(n); cin >> A;
    REP(i, n) A[i]--;
    vector<ll> L(n+1, 0);
    {
        vector<ll> cnt(m, 0);
        ll l = 0;
        REP(i, n) {
            cnt[A[i]]++;
            while (cnt[A[i]] >= 2) {
                cnt[A[l]]--;
                ++l;
            }
            assert(l <= i);
            L[i+1] = l;
        }
    }
    // cout << L << endl;
    SegmentTree<ll> dp(n+1, 0, [](int a, int b) { return (a + b) % mod; });
    dp.update(0, 1);
    FOR(j, 1, n+1) {
        ll l = L[j];
        ll r = j == n ? j+1 : j;
        dp.update(j, dp.find(l, r));
    }
    cout << dp.find(n, n+1) << endl;
}
