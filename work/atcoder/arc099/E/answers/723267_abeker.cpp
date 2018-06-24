#include <bits/stdc++.h>
using namespace std;

const int MAXN = 7e2 + 5;

int N, M;
bool mat[MAXN][MAXN];
int clr[MAXN];
bool dp[2 * MAXN][2];
int cnt;

void load() {
	scanf("%d%d", &N, &M);
	while (M--) {
		int a, b;
		scanf("%d%d", &a, &b);
		mat[a][b] = mat[b][a] = true;
	}
}

bool dfs(int x, int c) {
	if (clr[x] != -1)
		return clr[x] == c;
	clr[x] = c;
	cnt += c ? 1 : -1;
	for (int i = 1; i <= N; i++)
		if (i != x && !mat[x][i] && !dfs(i, c ^ 1))
			return false;
	return true;
}

bool ok(int val) {
	return val >= 0 && val < 2 * MAXN;
}

int solve() {
	memset(clr, -1, sizeof clr);
	dp[MAXN][0] = true;
		
	int c = 0;
	for (int i = 1; i <= N; i++)
		if (clr[i] == -1) {
			cnt = 0;
			if (!dfs(i, 0))
				return -1;
			c ^= 1;
			for (int i = 0; i < 2 * MAXN; i++) {
				dp[i][c] = false;
				if (ok(i + cnt))
					dp[i][c] |= dp[i + cnt][c ^ 1];
				if (ok(i - cnt))
					dp[i][c] |= dp[i - cnt][c ^ 1];
			}
		}
	
	int mn = 2 * MAXN;
	for (int i = 0; i < 2 * MAXN; i++)
		if (dp[i][c])
			mn = min(mn, abs(i - MAXN));
	
	int l = (N + mn) / 2;
	int r = (N - mn) / 2;
	return l * (l - 1) / 2 + r * (r - 1) / 2;
}

int main() {
	load();
	printf("%d\n", solve());
	return 0;
}