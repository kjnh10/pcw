#include <bits/stdc++.h>
using namespace std;

const long long mod = 1e9 + 7;
const int dy[] = { 0, 1, 0, -1 };
const int dx[] = { 1, 0, -1, 0 };

int a[1000][1000];
long long dp[1000][1000];

int main() {
	int h, w;
	cin >> h >> w;

	vector<tuple<int, int, int>> b;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			scanf("%d", &a[i][j]);
			dp[i][j] = 1;
			b.emplace_back(a[i][j], i, j);
		}
	}
	sort(b.begin(), b.end());

	for (int i = 0; i < h * w; i++) {
		int y, x;
		tie(ignore, y, x) = b[i];

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= h || nx >= w) continue;
			if (a[ny][nx] <= a[y][x]) continue;
			(dp[ny][nx] += dp[y][x]) %= mod;
		}
	}

	long long ans = 0;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			(ans += dp[i][j]) %= mod;
		}
	}
	cout << ans << endl;
}