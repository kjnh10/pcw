// need
#include <iostream>
#include <algorithm>

// data structure
#include <bitset>
//#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
//#include <array>
//#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <complex>
//#include <deque>
#include<valarray>

// stream
//#include <istream>
//#include <sstream>
//#include <ostream>

// etc
#include <cassert>
#include <functional>
#include <iomanip>
//#include <typeinfo>
#include <chrono>
#include <random>
#include <numeric>

#define INIT std::ios::sync_with_stdio(false);std::cin.tie(0);
#define VAR(type, ...)type __VA_ARGS__;MACRO_VAR_Scan(__VA_ARGS__);
template<typename T> void MACRO_VAR_Scan(T& t) { std::cin >> t; }
template<typename First, typename...Rest>void MACRO_VAR_Scan(First& first, Rest&...rest) { std::cin >> first; MACRO_VAR_Scan(rest...); }
#define VEC_ROW(type, n, ...)std::vector<type> __VA_ARGS__;MACRO_VEC_ROW_Init(n, __VA_ARGS__); for(int i=0; i<n; ++i){MACRO_VEC_ROW_Scan(i, __VA_ARGS__);}
template<typename T> void MACRO_VEC_ROW_Init(int n, T& t) { t.resize(n); }
template<typename First, typename...Rest>void MACRO_VEC_ROW_Init(int n, First& first, Rest&...rest) { first.resize(n); MACRO_VEC_ROW_Init(n, rest...); }
template<typename T> void MACRO_VEC_ROW_Scan(int p, T& t) { std::cin >> t[p]; }
template<typename First, typename...Rest>void MACRO_VEC_ROW_Scan(int p, First& first, Rest&...rest) { std::cin >> first[p]; MACRO_VEC_ROW_Scan(p, rest...); }
#define OUT(d) std::cout<<d;
#define FOUT(n, d) std::cout<<std::fixed<<std::setprecision(n)<<d;
#define SOUT(n, c, d) std::cout<<std::setw(n)<<std::setfill(c)<<d;
#define SP std::cout<<" ";
#define TAB std::cout<<"\t";
#define BR std::cout<<"\n";
#define ENDL std::cout<<std::endl;
#define FLUSH std::cout<<std::flush;
#define VEC(type, c, n) std::vector<type> c(n);for(auto& i:c)std::cin>>i;
#define MAT(type, c, m, n) std::vector<std::vector<type>> c(m, std::vector<type>(n));for(auto& r:c)for(auto& i:r)std::cin>>i;
#define ALL(a) (a).begin(),(a).end()
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define RFOR(i, a, b) for(int i=(b)-1;i>=(a);--i)
#define REP(i, n) for(int i=0;i<int(n);++i)
#define RREP(i, n) for(int i=(n)-1;i>=0;--i)
#define FORLL(i, a, b) for(ll i=ll(a);i<ll(b);++i)
#define RFORLL(i, a, b) for(ll i=ll(b)-1;i>=ll(a);--i)
#define REPLL(i, n) for(ll i=0;i<ll(n);++i)
#define RREPLL(i, n) for(ll i=ll(n)-1;i>=0;--i)
#define PAIR std::pair<int, int>
#define PAIRLL std::pair<ll, ll>
#define IN(a, x, b) (a<=x && x<b)
#define SHOW(d) {std::cerr << #d << "\t:" << d << "\n";}
#define SHOWVECTOR(v) {std::cerr << #v << "\t:";for(const auto& xxx : v){std::cerr << xxx << " ";}std::cerr << "\n";}
#define SHOWVECTOR2(v) {std::cerr << #v << "\t:\n";for(const auto& xxx : v){for(const auto& yyy : xxx){std::cerr << yyy << " ";}std::cerr << "\n";}}
#define SHOWPAIR(p) {std::cerr << #p << "\t:(" << p.first << ",\t" << p.second << ")\n";}
#define SHOWPAIRVECTOR2(v) {std::cerr << #v << "\t:\n";for(const auto& xxx : v){for(const auto& yyy : xxx){std::cerr<<'('<<yyy.first<<", "<<yyy.second<<") ";}std::cerr << "\n";}}
#define SHOWPAIRVECTOR(v) {for(const auto& xxx:v){std::cerr<<'('<<xxx.first<<", "<<xxx.second<<") ";}std::cerr<<"\n";}
#define SHOWQUEUE(a) {std::queue<decltype(a.front())> tmp(a);std::cerr << #a << "\t:";for(int i=0; i<static_cast<int>(a.size()); ++i){std::cerr << tmp.front() << "\n";tmp.pop();}std::cerr << "\n";}
template<typename T> inline T CHMAX(T& a, const T b) { return a = (a < b) ? b : a; }
template<typename T> inline T CHMIN(T& a, const T b) { return a = (a > b) ? b : a; }
#define EXCEPTION(msg) throw std::string("Exception : " msg " [ in ") + __func__ + " : " + std::to_string(__LINE__) + " lines ]"
#define TRY(cond, msg) try {if (cond) EXCEPTION(msg);}catch (std::string s) {std::cerr << s << std::endl;}
void CHECKTIME(std::function<void()> f) { auto start = std::chrono::system_clock::now(); f(); auto end = std::chrono::system_clock::now(); auto res = std::chrono::duration_cast<std::chrono::nanoseconds>((end - start)).count(); std::cerr << "[Time:" << res << "ns  (" << res / (1.0e9) << "s)]\n"; }

//#define int ll
using ll = long long;
using ull = unsigned long long;
constexpr int INFINT = 1 << 30;                          // 1.07x10^ 9
constexpr int INFINT_LIM = (1LL << 31) - 1;              // 2.15x10^ 9
constexpr ll INFLL = 1LL << 60;                          // 1.15x10^18
constexpr ll INFLL_LIM = (1LL << 62) - 1 + (1LL << 62);  // 9.22x10^18
constexpr double EPS = 1e-7;
constexpr int MOD = 1000000007;
constexpr double PI = 3.141592653589793238462643383279;

// write [ StarrySkyTree<> sst(n) ] when using this snippet.
template<typename T = ll, bool QUERY_IS_GETMAX = true>
struct StarrySkyTree {
	std::vector<T> seg, lazy;
	int size;
	T inf;
	std::function<T(T&, T&)> func;
	StarrySkyTree() {}
	StarrySkyTree(int n) : inf((QUERY_IS_GETMAX ? std::numeric_limits<T>::min() : std::numeric_limits<T>::max())), func([](T& a, T& b) {return (QUERY_IS_GETMAX ? std::max(a, b) : std::min(a, b)); }) {
		init(n);
	}
	void init(int n) {
		size = 1;
		while (size < n) size *= 2;
		seg.resize(size * 2);
		lazy.resize(size * 2);
	}
	void push(int k, int l, int r) {
		seg[k] += lazy[k]; seg[k] %= MOD;
		if (r - l > 1) {
			lazy[k * 2 + 1] += lazy[k]; lazy[k * 2 + 1] %= MOD;
			lazy[k * 2 + 2] += lazy[k]; lazy[k * 2 + 2] %= MOD;
		}
		lazy[k] = 0;
	}
	void update(int a, int b, T v, int k, int l, int r) {
		push(k, l, r);
		if (r <= a || b <= l) return;
		if (a <= l && r <= b) {
			lazy[k] += v; lazy[k] %= MOD;
			push(k, l, r);
		}
		else {
			update(a, b, v, k * 2 + 1, l, (l + r) / 2);
			update(a, b, v, k * 2 + 2, (l + r) / 2, r);
			seg[k] = func(seg[k * 2 + 1], seg[k * 2 + 2]);

		}
	}
	// add v to [a,b)
	void update(int a, int b, T v) {
		update(a, b, v, 0, 0, size);
	}
	T query(int a, int b, int k, int l, int r) {
		push(k, l, r);
		if (r <= a || b <= l) return inf;
		if (a <= l && r <= b) return seg[k];
		T vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
		T vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
		return func(vl, vr);
	}
	// return min(or max) in [a,b)
	T query(int a, int b) {
		return query(a, b, 0, 0, size);
	}
};

signed main() {
	INIT;
	VAR(int, n, m);
	VEC(int, f, n);

	std::vector<int> next(n, -1);
	int r = 0;
	std::set<int> set;
	REP(l, n) {
		while (r < n && set.find(f[r]) == set.end()) {
			set.insert(f[r++]);
		}
		CHMAX(next[l], r - 1);
		set.erase(f[l]);
	}
	StarrySkyTree<> sst(n + 1);
	sst.update(0, 1, 1);
	REP(i, n) {
		int t = sst.query(i, i + 1) % MOD;
		sst.update(i + 1, next[i] + 2, t);
	}
	OUT(sst.query(n, n + 1) % MOD)BR;
	return 0;
}