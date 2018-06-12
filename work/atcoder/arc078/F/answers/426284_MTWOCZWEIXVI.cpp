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

const int maxn = 16;

const int maxm = 15000000;

const int maxm2 = 1 << 15;

int n, m;
int g[maxn][maxn], chs[maxn];
int f[maxm], dp[maxm2][maxn], pw3[maxn];

int main()
{
	scf(n, m);
	rep(i, m){ int u, v; scf(u, v); --u; --v; scf(g[u][v]); g[v][u] = g[u][v]; }
	pw3[0] = 1;
	forn(i, 1, n) pw3[i] = pw3[i - 1] * 3;
	int Mask = 1 << n;
	rep(s, Mask) rep(i, n) dp[s][i] = iinf;
	for(int s = 2; s < pw3[n]; s += 3)
	{
		int t = s;
		static vi p1, p2; p1.clear(); p2.clear();
		rep(i, n)
		{
			chs[i] = t % 3, t /= 3;
			if(chs[i] == 1) p1.pb(i);
			if(chs[i] == 2) p2.pb(i);
		}
		if(SZ(p1) && SZ(p2))
		{
			int &u = p1[0];
			f[s] = f[s - pw3[u]];
			for(int v: p2) f[s] += g[u][v];
		}
		if(!SZ(p1) && !chs[n - 1])
		{
			int t = 0;
			for(int i: p2) t |= (1 << i);
			dp[t][0] = 0;
		}
	}
	int tmp;
	for(int s = 1; s < Mask; s += 2) rep(u, n) if((tmp = dp[s][u]) < iinf)
	{
		int base = (Mask - 1 ^ s);
		for(int t = base; ; t = (t - 1 & base))
		{
			int x = 0;
			rep(i, n)
			{
				if((s >> i) & 1) x += (pw3[i] << 1);
				if((t >> i) & 1) x += pw3[i];
			}
			int calc = tmp + f[x];
			rep(v, n) if(g[u][v] && ((t >> v) & 1)) chkmin(dp[s | t][v], calc - g[u][v]);
			if(!t) break;
		}
	}
	printf("%d\n", dp[Mask - 1][n - 1]);
	return 0;
}