// In the name of God

#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <deque>
#include <assert.h>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <math.h>
#include <bitset>
#include <iomanip>
#include <complex>

using namespace std;

#define rep(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
template<typename T> inline bool smin(T &a, const T &b)   { return a > b ? a = b : a;    }
template<typename T> inline bool smax(T &a, const T &b)   { return a < b ? a = b : a;    }

typedef long long LL;

const int N = (int) 1e5 + 5, mod = (int) 0;
int px[N], py[N], par[N];
pair<int, int> sx[N], sy[N];
int find(int x) { return x == par[x] ? x : par[x] = find(par[x]); }
int unite(int u, int v) {
	u = find(u);
	v = find(v);
	if (u == v) return 0;
	par[u] = v;
	return 1;
}
	
int dist(int x, int y) {
	return min(abs(px[x] - px[y]), abs(py[x] - py[y]));	
}
int main() {
	int n;
	cin >> n;
	for (int j = 0; j < n; ++j) {
		cin >> px[j] >> py[j];
		par[j] = j;
		sx[j] = mp(px[j], j);
		sy[j] = mp(py[j], j);
	}
	sort(sx, sx + n);
	sort(sy, sy + n);
	set<pair<int, pair<int, int>>> st;
	for (int j = 0; j < n - 1; ++j) {
		st.insert(mp(dist(sx[j].second, sx[j + 1].second), mp(sx[j].second, sx[j + 1].second)));	
		st.insert(mp(dist(sy[j].second, sy[j + 1].second), mp(sy[j].second, sy[j + 1].second)));	
	}
	long long res = 0;
	while ((int) st.size()) {
		auto cur = *(st.begin());
		st.erase(cur);
		int u = cur.second.first, v = cur.second.second;
		res += (LL) unite(u, v) * dist(u, v);
	}
	cout << res << endl;
}


