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
#define int long long
const int N = (int) 0, mod = (int) 0;

int32_t main() {
	int n, m;
	cin >> n >> m;
	int res = 1e18;
	for (int turn = 0; turn <= 1; ++turn) {
		swap(n, m);
		res = min(res, (n % 3) == 0 ? 0 : m);
		for (int j = 1; j <= n - 1; ++j) {
			int mx = j * m, mn = j * m;
			mx = max(mx, (n - j) * (m / 2 + (m % 2)));
			mn = min(mn, (n - j) * (m / 2));
			res = min(res, mx - mn);
		}
	}
	cout << res << endl;
}

