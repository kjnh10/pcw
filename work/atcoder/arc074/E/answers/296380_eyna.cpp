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

const int N = (int) 305, mod = (int) 1e9 + 7;
int dp[N][N], odp[N][N];
vector<pair<int, int>> proc[N];
void sadd(int &x, int y) {
	x += y;
	while (x >= mod) x -= mod;
}
int main() {
	int n, m;
	cin >> n >> m;
	for (int j = 0; j < m; ++j) {
		int l, r, k;
		cin >> l >> r >> k;
		proc[r].push_back(mp(l, k));
	}
	dp[0][0] = 1;
	for (int j = 1; j <= n; ++j) {
		memcpy(odp, dp, sizeof dp);
		memset(dp, 0, sizeof dp);
		for (int pl = 0; pl < j; ++pl)
			for (int pr = 0; pr < j; ++pr) {
				sadd(dp[pl][pr], odp[pl][pr]);
				sadd(dp[j - 1][pl], odp[pl][pr]);
				sadd(dp[j - 1][pr], odp[pl][pr]);
			}
		for (int pl = 0; pl < j; ++pl)
			for (int pr = 0; pr < j; ++pr) {
				for (auto q : proc[j]) {
					int l = q.first, k = q.second;
					int cnt = 1;
					if (l <= pl) ++cnt;
					if (l <= pr) ++cnt;
					if (k != cnt) dp[pl][pr] = 0;
				}
			}
	}
	int res = 0;
	for (int a = 0; a < N; ++a)
		for (int b = 0; b < N; ++b)
			sadd(res, dp[a][b]);
	cout << res << endl;
}








