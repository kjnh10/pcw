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
#define int long long
typedef long long LL;

const int N = (int) 3e5 + 5, mod = (int) 0;
int pre[N], suf[N], a[N];
int32_t main() {
	int n;
	cin >> n;
	for (int j = 0; j < 3 * n; ++j)
		cin >> a[j];
	{
		set<pair<int, int>, greater<pair<int, int>>> st;
		long long sum = 0;
		for (int j = 2 * n + 1; j < 3 * n; ++j) sum += a[j], st.insert(mp(a[j], j));
		for (int s = 2 * n; s >= n; --s) {
			st.insert(mp(a[s], s));
			sum += a[s];
			while ((int) st.size() > n) {
				auto cur = *(st.begin());
				sum -= cur.first;
				st.erase(cur);
			}
			suf[s] = sum;
		}
	}
	{
		set<pair<int, int>> st;
		int sum = 0;
		for (int j = 0; j < n - 1; ++j) sum += a[j], st.insert(mp(a[j], j));
		for (int j = n - 1; j < 2 * n; ++j) {
			st.insert(mp(a[j], j));
			sum += a[j];
			while ((int) st.size() > n) {
				auto cur = *(st.begin());
				sum -= cur.first;
				st.erase(cur);
			}
			pre[j] = sum;
		}
	}
	long long res = -1e18;
	for (int j = n - 1; j < 2 * n; ++j) {
		res = max(res, pre[j] - suf[j + 1]);
	}
	cout << res << endl;
}

