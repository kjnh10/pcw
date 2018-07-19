//#define ONLINE_JUDGE
#include<bits/stdc++.h>

#define HEAP priority_queue
#define rep(i, n) for(int i = 0, _end_ = (n); i < _end_; ++i)
#define per(i, n) for(int i = (n) - 1; i >= 0 ; --i)
#define forn(i, l, r) for(int i = (l), _end_ = (r); i <= _end_; ++i)
#define nrof(i, r, l) for(int i = (r), _end_ = (l); i >= _end_; --i)
#define FOR(a, b) for(auto (a): (b))
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define X first
#define Y second
#define eps 1e-6
#define pi 3.1415926535897932384626433832795
#define SZ(x) (int)x.size()
#define ALL(x) x.begin(), x.end()
#define FILL(a, b) memset((a), (b), sizeof((a)))
#define MCPY(a, b) memcpy((a), (b), sizeof((b)))

using namespace std;

typedef long long LL;
typedef double flt;
typedef vector<int> vi;
typedef vector<LL> vl;
typedef pair<int,int> pii;
typedef pair<int,LL> pil;
typedef pair<LL,int> pli;
typedef pair<LL,LL> pll;
typedef vector<pil> vil;
typedef vector<pii> vii;
typedef vector<pli> vli;
typedef vector<pll> vll;

const int iinf = 1e9 + 7;
const int oo = 0x3f3f3f3f;
const LL linf = 1ll << 60;
const flt dinf = 1e60;

template <typename T>
inline void scf(T &x)
{
	bool f = 0; x = 0; char c = getchar();
	while((c < '0' || c > '9') && c != '-') c = getchar();
	if(c == '-') { f = 1; c = getchar(); }
	while(c >= '0' && c <= '9') { x = x * 10 + c - '0'; c = getchar(); }
	if(f) x = -x; return;
}
template <typename T1, typename T2>
void scf(T1 &x, T2 &y) { scf(x); return scf(y); }
template <typename T1, typename T2, typename T3>
void scf(T1 &x, T2 &y, T3 &z) { scf(x); scf(y); return scf(z); }
template <typename T1, typename T2, typename T3, typename T4>
void scf(T1 &x, T2 &y, T3 &z, T4 &w) { scf(x); scf(y); scf(z); return scf(w); }

inline char mygetchar(){ char c = getchar(); while(c == ' ' || c == '\n') c = getchar(); return c; }

template <typename T> inline bool chkmax(T &x, const T &y){ return y > x ? x = y, 1 : 0; }
template <typename T> inline bool chkmin(T &x, const T &y){ return y < x ? x = y, 1 : 0; }

#ifdef ONLINE_JUDGE
#define debug(...) ;
#else
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define DEBUG
#endif

//---------------------------------------------------------head----------------------------------------------------

const int maxn = 4e5 + 100;

int n, m;
char s[maxn], t[maxn];
LL cnt[maxn][26], cnt2[maxn][26];
LL l, r;
LL ans[26];
int border[maxn];

void KMP()
{
	border[0] = -1;
	forn(i, 1, n)
	{
		t[++m] = s[i];
		int j = border[i - 1];
		while(~j && s[j + 1] != s[i]) j = border[j];
		border[i] = j + 1;
	}
	int l = border[n / 2];
	forn(i, l + 1, n - l) t[++m] = s[i];
	return;
}

void Q(LL N, int opr)
{
	if(!N) return;
	static vl fib; fib.clear();
	fib.pb(n / 2); fib.pb(m / 2);
	if(N <= (LL)m / 2)
	{
		rep(i, 26) ans[i] += 1ll * opr * cnt2[N][i];
		return;
	}
	while(fib.back() <= N) fib.pb(fib.back() + fib[SZ(fib) - 2]);
	static LL A[26], B[26], C[26];
	memcpy(A, cnt[n / 2], sizeof(cnt[n / 2]));
	memcpy(B, cnt2[m / 2], sizeof(cnt2[m / 2]));
	forn(i, 2, SZ(fib) - 2)
	{
		memset(C, 0, sizeof C);
		rep(j, 26) C[j] = A[j] + B[j];
		memcpy(A, B, sizeof A);
		memcpy(B, C, sizeof B);
	}
	rep(i, 26) ans[i] += 1ll * opr * B[i];
	Q(N - fib[SZ(fib) - 2], opr);
	return;
}

void fQ(LL N, int opr)
{
	if(!N) return;
	static vl fib; fib.clear();
	fib.pb(n); fib.pb(m);
	if(N <= (LL)m)
	{
		rep(i, 26) ans[i] += 1ll * opr * cnt2[N][i];
		return;
	}
	while(fib.back() <= N) fib.pb(fib.back() + fib[SZ(fib) - 2]);
	static LL A[26], B[26], C[26];
	memcpy(A, cnt[n], sizeof(cnt[n]));
	memcpy(B, cnt2[m], sizeof(cnt2[m]));
	forn(i, 2, SZ(fib) - 2)
	{
		memset(C, 0, sizeof C);
		rep(j, 26) C[j] = A[j] + B[j];
		memcpy(A, B, sizeof A);
		memcpy(B, C, sizeof B);
	}
	rep(i, 26) ans[i] += 1ll * opr * B[i];
#ifdef DEBUG
	rep(i, 26) printf("%lld ", ans[i]); puts("");
#endif
	Q(N - fib[SZ(fib) - 2], opr);
	return;
}

int main()
{
	scanf("%s", s + 1); scf(l, r); n = strlen(s + 1);
	forn(i, 1, n) cnt[i][s[i] - 'a'] = 1;
	forn(i, 1, n) rep(j, 26) cnt[i][j] += cnt[i - 1][j];
	KMP();
	forn(i, 1, m) cnt2[i][t[i] - 'a'] = 1;
	forn(i, 1, m) rep(j, 26) cnt2[i][j] += cnt2[i - 1][j];
	Q(r, 1);
	Q(l - 1, -1);
	rep(i, 26) printf("%lld ", ans[i]);
	return 0;
}