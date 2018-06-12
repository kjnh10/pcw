#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); i--)
#define FORall(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define sz(a) int((a).size())
#define pconent(t, x) (t.find(x) != t.end())
#define all(a) (a).begin(), (a).end()
#define uni(a) (a).erase(unique(all(a)), (a).end())
#define pb push_back
#define pf push_front
#define mp make_pair
#define fi first
#define se second
#define prec(n) fixed<<setprecision(n)
#define bit(n, i) (((n) >> (i)) & 1)
#define bitcount(n) __builtin_popcountll(n)
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
const int MOD = (int) 1e9 + 7;
const int FFTMOD = 1007681537;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = acos((ld) -1);
const ld EPS = 1e-9;
inline ll gcd(ll a, ll b) {ll r; while (b) {r = a % b; a = b; b = r;} return a;}
inline ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
inline ll fpow(ll n, ll k, int p = MOD) {ll r = 1; for (; k; k >>= 1) {if (k & 1) r = r * n % p; n = n * n % p;} return r;}
template<class T> inline int chkmin(T& a, const T& val) {return val < a ? a = val, 1 : 0;}
template<class T> inline int chkmax(T& a, const T& val) {return a < val ? a = val, 1 : 0;}
inline ll isqrt(ll k) {ll r = sqrt(k) + 1; while (r * r > k) r--; return r;}
inline ll icbrt(ll k) {ll r = cbrt(k) + 1; while (r * r * r > k) r--; return r;}
inline void addmod(int& a, int val, int p = MOD) {if ((a = (a + val)) >= p) a -= p;}
inline void submod(int& a, int val, int p = MOD) {if ((a = (a - val)) < 0) a += p;}
inline int mult(int a, int b, int p = MOD) {return (ll) a * b % p;}
inline int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}
inline int sign(ld x) {return x < -EPS ? -1 : x > +EPS;}
inline int sign(ld x, ld y) {return sign(x - y);}
#define db(x) cerr << #x << " = " << (x) << " ";
#define endln cerr << "\n";

const int maxn = 1e5 + 5;
int n;
vi adj[maxn];
int mi;
pi dp[maxn];

int func(vi& vals, int x) {
    int ptr = sz(vals) - 1;
    int num = 0;
    FOR(i, 0, sz(vals)) if (i != x) {
        while (ptr > i && vals[i] + vals[ptr] > mi) {
            ptr--;
        }
        if (ptr == x) ptr--;
        if (ptr <= i) {
            break;
        }
        num++;
        ptr--;
    }
    return num;
}

pi calc(int u, int p) {
    pi& res = dp[u];
    if (res != mp(-1, -1)) return res;
    res = mp(INF, INF);
    vi vals;
    int tot = 0;
    for (int v : adj[u]) {
        if (v != p) {
            pi r = calc(v, u);
            tot += r.fi;
            vals.pb(r.se + 1);
        }
    }
    vi tmp = vals;
    sort(all(vals));
    int mx = func(vals, sz(vals) - 1);
    int lo = 0, hi = sz(vals) - 1;
    while (lo < hi) {
        int m = lo + hi >> 1;
        if (func(vals, m) < mx) {
            lo = m + 1;
        }
        else {
            hi = m;
        }
    }
    int m = lo + hi >> 1;
    int cnt = 0;
    for (int v : adj[u]) {
        if (v != p) {
            int sum = tot + sz(tmp) - mx - 1;
            if (tmp[cnt] < vals[m]) {
                sum++;
            }
            if (tmp[cnt] == mi) {
                chkmin(res, mp(sum + 1, 0));
            }
            else {
                chkmin(res, mp(sum, tmp[cnt]));
            }
            cnt++;
        }
    }
    chkmin(res, mp(tot + sz(tmp) - func(vals, -1), 0));
    return res;
}

inline int ff(pi p) {
    return p.fi + (p.se > 0);
}

void solve() {
    cin >> n;
    FOR(i, 0, n - 1) {
        int u, v; cin >> u >> v; u--, v--;
        adj[u].pb(v), adj[v].pb(u);
    }
    fill_n(dp, n, mp(-1, -1));
    mi = n;
    pi mn = calc(0, -1);
    int lo = 1, hi = n;
    while (lo < hi) {
        mi = lo + hi >> 1;
        fill_n(dp, n, mp(-1, -1));
        if (ff(calc(0, -1)) > ff(mn)) {
            lo = mi + 1;
        }
        else {
            hi = mi;
        }
    }
    mi = lo + hi >> 1;
    cout << ff(mn) << " " << mi << "\n";
}

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(0), cin.tie(0);
    if (argc > 1) {
        assert(freopen(argv[1], "r", stdin));
    }
    if (argc > 2) {
        assert(freopen(argv[2], "wb", stdout));
    }
    solve();
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}
