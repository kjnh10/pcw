#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORd(i, a, b) for (int i = (a) - 1; i >= (b); i--)
#define FORall(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
#define sz(a) int((a).size())
#define present(t, x) (t.find(x) != t.end())
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
const int MOD2 = 1007681537;
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

const int maxn = 2000 + 5;
int n, m;
int a[maxn][maxn];
int b[maxn][maxn];

int maxHist(int row[], int C)
{
    stack<int> result;
 
    int top_val;
 
    int max_area = 0;
 
    int area = 0;
 
    int i = 0;
    while (i < C)
    {
        if (result.empty() || row[result.top()] <= row[i])
            result.push(i++);
 
        else
        {
            top_val = row[result.top()];
            result.pop();
            area = (top_val + 1) * (i + 1);
 
            if (!result.empty())
                area = (top_val + 1) * (i - result.top() - 1 + 1);
            max_area = max(area, max_area);
        }
    }
 
    while (!result.empty())
    {
        top_val = row[result.top()];
        result.pop();
        area = (top_val + 1) * (i + 1);
        if (!result.empty())
            area = (top_val + 1) * (i - result.top() - 1 + 1);
 
        max_area = max(area, max_area);
    }
    return max_area;
}
 
int maxRectangle(int A[][maxn], int R, int C)
{
    int result = maxHist(A[0], C);
    for (int i = 1; i < R; i++)
    {
 
        for (int j = 0; j < C; j++)
            if (A[i][j]) A[i][j] += A[i - 1][j];
        result = max(result, maxHist(A[i], C));
    }
 
    return result;
}

void solve() {
    cin >> n >> m;
    FOR(i, 0, n) {
        string s; cin >> s;
        FOR(j, 0, m) a[i][j] = s[j] == '#';
    }
    FOR(i, 0, n - 1) FOR(j, 0, m - 1) {
        b[i][j] = a[i][j] ^ a[i + 1][j] ^ a[i][j + 1] ^ a[i + 1][j + 1] ^ 1;
    }
    int ans = max(n, m);
    chkmax(ans, maxRectangle(b, n - 1, m - 1));
    cout << ans << "\n";
}

int main() {
    int JUDGE_ONLINE = 1;
    if (fopen("in.txt", "r")) {
        JUDGE_ONLINE = 0;
        assert(freopen("in.txt", "r", stdin));
        //assert(freopen("out.txt", "w", stdout));
    }
    else {
        ios_base::sync_with_stdio(0), cin.tie(0);
    }
    solve();
    if (!JUDGE_ONLINE) {
        //cout << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    }
    return 0;
}