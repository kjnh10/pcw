#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

const int MOD = (int)1e9 + 7;
int add(int x, int y) {
	x += y;
	if (x >= MOD) return x - MOD;
	return x;
}
int sub(int x, int y) {
	x -= y;
	if (x < 0) return x + MOD;
	return x;
}
int mult(int x, int y) {
	return ((ll)x * y) % MOD;
}

const int N = 5002;
int C[N][N];
int f[N];
int n;
vector<int> g[N];
int sz[N];
int a[N];
int m;
int dp[2][N];

void dfs(int v, int par) {
	sz[v] = 1;
	for (int u : g[v]) {
		if (u == par) continue;
		dfs(u, v);
		sz[v] += sz[u];
	}
}

void solve() {
	dp[0][0] = 1;
	for (int i = 0; i < m; i++) {
		for (int x = 0; x <= n; x++)
			dp[1][x] = 0;
		for (int x = 0; x <= n; x++) {
			if (dp[0][x] == 0) continue;
			for (int y = 0; y <= a[i]; y++)
				dp[1][x + y] = add(dp[1][x + y], mult(mult(dp[0][x], f[y]), mult(C[a[i]][y], C[a[i]][y])));
		}
		for (int x = 0; x <= n; x++)
			dp[0][x] = dp[1][x];
	}
	int ans = 0;
	for (int x = 0; x <= n; x++) {
		int val = mult(dp[0][x], f[n - x]);
		if (x & 1)
			ans = sub(ans, val);
		else
			ans = add(ans, val);
	}
	printf("%d\n", ans);
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	for (int i = 0; i < N; i++)
		C[i][0] = C[i][i] = 1;
	for (int i = 0; i < N; i++)
		for (int j = 1; j < i; j++)
			C[i][j] = add(C[i - 1][j - 1], C[i - 1][j]);
	f[0] = 1;
	for (int i = 1; i < N; i++)
		f[i] = mult(f[i - 1], i);

	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int v, u;
		scanf("%d%d", &v, &u);
		v--;u--;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	dfs(0, -1);
	int v = 0;
	while(true) {
		int w = -1;
		for (int u : g[v]) {
			if (sz[u] > sz[v]) continue;
			if (2 * sz[u] >= n)
				w = u;
		}
		if (w == -1) break;
		v = w;
	}
	dfs(v, -1);
	for (int u : g[v]) {
		a[m] = sz[u];
		if (2 * a[m] > n) throw;
		if (2 * a[m] == n) {
			printf("%d\n", mult(f[a[m]], f[a[m]]));
			return 0;
		}
		m++;
	}
	solve();

	return 0;
}
