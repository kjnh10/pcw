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

inline unsigned long long popCount(unsigned long long x) {
	x = ((x & 0xaaaaaaaaaaaaaaaaUL) >> 1) + (x & 0x5555555555555555UL);
	x = ((x & 0xccccccccccccccccUL) >> 2) + (x & 0x3333333333333333UL);
	x = ((x & 0xf0f0f0f0f0f0f0f0UL) >> 4) + (x & 0x0f0f0f0f0f0f0f0fUL);
	x = ((x & 0xff00ff00ff00ff00UL) >> 8) + (x & 0x00ff00ff00ff00ffUL);
	x = ((x & 0xffff0000ffff0000UL) >> 16) + (x & 0x0000ffff0000ffffUL);
	x = ((x & 0xffffffff00000000UL) >> 32) + (x & 0x00000000ffffffffUL);
	return x;
}

constexpr int n = 5;

inline int calc(int r, int c) {
	return r * n + c; 
}

int dp[1 << (n * n)];

signed main() {
	INIT;
	MAT(int, x, n, n);
	std::set<int> set;
	std::vector<int> pos(n*n);
	REP(i, n) REP(j, n) {
		if (x[i][j] == 0) continue;
		set.insert(x[i][j] - 1);
		pos[x[i][j] - 1] = i * n + j;
	}
	dp[0] = 1;
	REP(i, (1 << (n*n)) - 1) {
		int v = popCount(i);
		if (set.find(v) != set.end()) {
			if ((i >> pos[v]) & 1) continue;
			int r = pos[v] / n, c = pos[v] % n;
			if (IN(1, r, n-1)) {
				int nextR = 0;
				if ((i >> calc(r - 1, c + 0)) & 1) ++nextR;
				if ((i >> calc(r + 1, c + 0)) & 1) ++nextR;
				if (nextR == 1) continue;
			}
			if (IN(1, c, n - 1)) {
				int nextC = 0;
				if ((i >> calc(r + 0, c - 1)) & 1) ++nextC;
				if ((i >> calc(r + 0, c + 1)) & 1) ++nextC;
				if (nextC == 1) continue;
			}
			int t = i | (1 << pos[v]);
			dp[t] += dp[i];
			dp[t] %= MOD;
		}
		else {
			REP(j, (n*n)) {
				if ((i >> j) & 1) continue;
				int r = j / n, c = j % n;
				if (IN(1, r, n - 1)) {
					int nextR = 0;
					if ((i >> calc(r - 1, c + 0)) & 1) ++nextR;
					if ((i >> calc(r + 1, c + 0)) & 1) ++nextR;
					if (nextR == 1) continue;
				}
				if (IN(1, c, n - 1)) {
					int nextC = 0;
					if ((i >> calc(r + 0, c - 1)) & 1) ++nextC;
					if ((i >> calc(r + 0, c + 1)) & 1) ++nextC;
					if (nextC == 1) continue;
				}
				int t = i | (1 << j);
				dp[t] += dp[i];
				dp[t] %= MOD;
			}
		}
	}
	OUT(dp[(1 << (n*n)) - 1])BR;
	return 0;
}