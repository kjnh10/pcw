// tzl ak IOI! 

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
const LL linf = 10000000000010;
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

template <typename T>
void chkmax(T &x, const T &y){ if(y > x) x = y; return; }

template <typename T>
void chkmin(T &x, const T &y){ if(y < x) x = y; return; }

#define ONLINE_JUDGE

#ifdef ONLINE_JUDGE
#define debug(x,c) ;
#else
#define DEBUG
#define debug(x,c) cerr<<#x<<"="<<x<<c;
#endif

void TZL();

void RANK1();

#define tzl int
#define ak main
#define IOI ()
tzl ak IOI
{
#undef tzl
#undef ak
#undef IOI

	TZL();
	RANK1();

#define tzl return
#define caisi 0
#define myy ;
	tzl caisi myy
#undef tzl
#undef caisi
#undef myy
}

//---------------------------head----------------------------

const int N = 2e5 + 100;

struct seg
{
	int n;
	LL num[N << 2], tag[N << 2];

	int L(int i){ return i << 1; }
	int R(int i){ return (i << 1) | 1; }

	void push(int i)
	{
		if(tag[i])
		{
			int l = L(i), r = R(i);
			tag[l] += tag[i]; tag[r] += tag[i];
			num[l] += tag[i]; num[r] += tag[i];
			tag[i] = 0;
		}
		return;
	}

	void pull(int i)
	{
		num[i] = min(num[L(i)], num[R(i)]);
		return;
	}

	void M(int a, int b, LL x, int l, int r, int k)
	{
		if(a == l && b == r)
		{
			num[k] += x; tag[k] += x;
			return;
		}

		int mid = l + r >> 1; push(k);
		if(a > mid) M(a, b, x, mid + 1, r, R(k));
		else if(b <= mid) M(a, b, x, l, mid, L(k));
		else M(a, mid, x, l, mid, L(k)), M(mid + 1, b, x, mid + 1, r, R(k));
		return pull(k);
	}

	LL Q(int a, int b, int l, int r, int k)
	{
		if(a == l && b == r) return num[k];

		int mid = l + r >> 1; push(k);
		if(a > mid) return Q(a, b, mid + 1, r, R(k));
		if(b <= mid) return Q(a, b, l, mid, L(k));
		return min(Q(a, mid, l, mid, L(k)), Q(mid + 1, b, mid + 1, r, R(k)));
	}

	void B(int l, int r, int k, LL *a)
	{
		if(l == r)
		{
			num[k] = a[l];
			return;
		}

		int mid = l + r >> 1;
		B(l, mid, L(k), a);
		B(mid + 1, r, R(k), a);
		return pull(k);
	}

	void S(int i, LL x, int l, int r, int k)
	{
		if(l == r)
		{
			num[k] = x; tag[k] = 0;
			return;
		}

		int mid = l + r >> 1; push(k);
		if(i <= mid) S(i, x, l, mid, L(k));
		else S(i, x, mid + 1, r, R(k));
		return pull(k);
	}

	void S(int i, LL x)
	{
		return S(i, x, 1, n, 1);
	}

	void B(int _n, LL *a)
	{
		n = _n;
		B(1, n, 1, a);
		return;
	}

	void M(int a, int b, LL x)
	{
		if(a <= b) return M(a, b, x, 1, n, 1);
		return;
	}

	LL Q(int a, int b)
	{
		return (a <= b) ? Q(a, b, 1, n, 1) : linf;
	}
}A, B, a1, a2, b1, b2;

int n, range;
int x[N];

void TZL()
{
	scf(range); scf(n); n += 2;
	scf(x[1], x[2]);
	forn(i, 3, n) scf(x[i]);

	static LL a[N];
	rep(i, N) a[i] = linf;

	A.B(n, a);
	a1.B(range, a);
	a2.B(range, a);

	a[1] = 0;
	B.B(n, a);
	a[1] = linf;
	a[x[1]] = x[1];
	b1.B(range, a);
	a[x[1]] = -x[1];
	b2.B(range, a);
	return;
}

LL Q(seg &s1, seg &s2, const int &x)
{
	LL r1 = s1.Q(x, range), r2 = s2.Q(1, x);
	return min(r1 - (LL)x, r2 + (LL)x);
}

void RANK1()
{
	forn(i, 3, n)
	{
		LL a = Q(a1, a2, x[i]), b = Q(b1, b2, x[i]);
#ifdef DEBUG
		printf("%lld %lld\n", a, b);
#endif
		LL d = abs(x[i] - x[i - 1]);

		A.M(1, n, d); B.M(1, n, d);
		a1.M(1, range, d); b1.M(1, range, d);
		a2.M(1, range, d); b2.M(1, range, d);

		LL ac = A.Q(i - 1, i - 1), bc = B.Q(i - 1, i - 1);
		if(b < ac)
		{
#ifdef DEBUG
			printf("\t%lld %lld\n", ac, b);
#endif
			A.S(i - 1, b);
			a1.S(x[i - 1], b + x[i - 1]);
			a2.S(x[i - 1], b - x[i - 1]);
#ifdef DEBUGG
			cerr<<"\t\t"<<a1.Q(1, range)<<endl;
			cerr<<"\t\t"<<a2.Q(1, range)<<endl;
#endif
		}
		if(a < bc)
		{
#ifdef DEBUG
			printf("\t%lld %lld\n", bc, a);
#endif
			B.S(i - 1, a);
			b1.S(x[i - 1], a + x[i - 1]);
			b2.S(x[i - 1], a - x[i - 1]);
		}
	}
	printf("%lld\n", min(A.Q(1, n), B.Q(1, n)));
	return;
}