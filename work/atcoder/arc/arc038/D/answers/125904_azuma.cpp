#include <bits/stdc++.h>
using namespace std;

int H, W;
int dp[100][100][2];
char c[100][100];
const int dx[] = { 1, 0, 1 };
const int dy[] = { 0, 1, 1 };

int dfs(int x, int y, int t) {
	if (dp[x][y][t]) {
		return dp[x][y][t] - 1;
	}
	bool res = 1 - t;
	for (int i = 0; i < 3; i++) {
		int tx = x + dx[i], ty = y + dy[i];
		if (tx < H && ty < W && c[tx][ty] == '.' && dfs(tx, ty, 1 - t) == t) {
			res = t;
			break;
		}
	}
	dp[x][y][t] = res + 1;
	dp[x][y][1 - t] = 1 - res + 1;
	return res;
}

int main()
{
	cin >> H >> W;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> c[i][j];
		}
	}
	cout << (dfs(0, 0, 1) ? "First" : "Second") << endl;
	return 0;
}
