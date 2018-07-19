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

const int N = 1010;
const int C = 5002;
int dp[N];
int n;
int a[N];
vector<int> g[N];

void dfs(int v) {
	dp[v] = -1;
	if (g[v].empty()) {
		dp[v] = 0;
		return;
	}
	int inner[2][C];
	for (int i = 0; i < C; i++)
		inner[0][i] = 0;
	for (int u : g[v]) {
		dfs(u);
		if (dp[u] == -1) {
			dp[v] = -1;
			return;
		}
		for (int i = 0; i < C; i++)
			inner[1][i] = -1;
		for (int x = 0; x < C; x++) {
			if (inner[0][x] == -1) continue;
			if (x + a[u] < C) {
				int w = inner[0][x] + dp[u];
				if (inner[1][x + a[u]] == -1 || inner[1][x + a[u]] > w)
					inner[1][x + a[u]] = w;
			}
			if (x + dp[u] < C) {
				int w = inner[0][x] + a[u];
				if (inner[1][x + dp[u]] == -1 || inner[1][x + dp[u]] > w)
					inner[1][x + dp[u]] = w;
			}
		}
		for (int x = 0; x < C; x++)
			inner[0][x] = inner[1][x];
	}
	for (int x = 0; x <= a[v]; x++) {
		if (inner[0][x] == -1) continue;
		if (dp[v] == -1 || dp[v] > inner[0][x])
			dp[v] = inner[0][x];
	}
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int v;
		scanf("%d", &v);
		v--;
		g[v].push_back(i);
	}
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	dfs(0);
	for (int i = 0; i < n; i++)
		if (dp[i] == -1) {
			printf("IMPOSSIBLE\n");
			return 0;
		}
	printf("POSSIBLE\n");

	return 0;
}
