#include <bits/stdc++.h>

#define _overload(_1,_2,_3,name,...) name
#define _rep(i,n) _range(i,0,n)
#define _range(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload(__VA_ARGS__,_range,_rep,)(__VA_ARGS__)

#define _rrep(i,n) _rrange(i,n,0)
#define _rrange(i,a,b) for(int i=int(a)-1;i>=int(b);--i)
#define rrep(...) _overload(__VA_ARGS__,_rrange,_rrep,)(__VA_ARGS__)

#define _all(arg) begin(arg),end(arg)
#define uniq(arg) sort(_all(arg)),(arg).erase(unique(_all(arg)),end(arg))
#define getidx(ary,key) lower_bound(_all(ary),key)-begin(ary)
#define clr(a,b) memset((a),(b),sizeof(a))
#define bit(n) (1LL<<(n))
#define popcount(n) (__builtin_popcountll(n))

using namespace std;

template<class T>bool chmax(T &a, const T &b) { return (a < b) ? (a = b, 1) : 0;}
template<class T>bool chmin(T &a, const T &b) { return (b < a) ? (a = b, 1) : 0;}

using ll = long long;
using R = long double;
const R EPS = 1e-9L; // [-1000,1000]->EPS=1e-8 [-10000,10000]->EPS=1e-7
inline int sgn(const R& r) {return (r > EPS) - (r < -EPS);}
inline R sq(R x) {return sqrt(max(x, 0.0L));}

const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

// Problem Specific Parameter:

const ll mod = 1000000007LL;

int h, w;
map<vector<int>, ll> dp[110][10];


auto normalize(const vector<int> &c) {
	vector<int> ary = {0};
	rep(i, h) if (c[i] >= 0) ary.push_back(c[i]);

	sort(begin(ary), end(ary));
	ary.erase(unique(begin(ary), end(ary)), end(ary));

	vector<int> ret(h, -1);
	rep(i, h) if (c[i] >= 0) ret[i] = lower_bound(begin(ary), end(ary), c[i]) - begin(ary);
	return ret;
}


auto white(const vector<int> &c, int pos) {
	vector<int> ret = c;
	ret[pos] = -1;
	return normalize(ret);
}

auto black(const vector<int> &c, int pos) {
	vector<int> ret = c;

	if (pos > 0 and c[pos - 1] != -1 and c[pos] != -1) {
		int a = c[pos - 1], b = c[pos];
		if (a > b) swap(a, b);
		rep(i, h) if (ret[i] == b) ret[i] = a;
	}

	int nxt = max(0, *max_element(begin(ret), end(ret))) + 1;
	if (ret[pos] != -1) nxt = ret[pos];
	if (pos > 0 and ret[pos - 1] != -1) nxt = ret[pos - 1];
	ret[pos] = nxt;

	return normalize(ret);
}

int main(void) {
	cin >> h >> w;

	vector<int> init(h, -1);
	init[0] = 0;
	dp[0][1][init] = 1LL;

	rep(i, w)rep(j, h) {
		int ni = i, nj = j + 1;
		if (nj == h) ni++, nj = 0;

		for (const  auto &cur : dp[i][j]) {
			for (const auto &nxt : {white(cur.first, j), black(cur.first, j)}) {
				dp[ni][nj][nxt] = (dp[ni][nj][nxt] + cur.second) % mod;
			}
		}
	}

	ll ans = 0LL;
	for (auto &elem : dp[w][0]) if (elem.first[h - 1] == 0) ans = (ans + elem.second) % mod;
	cout << ans << endl;

	return 0;
}