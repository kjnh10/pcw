#pragma GCC optimize ("O3", "unroll-loops")
#include <bits/stdc++.h>

using namespace std;
const int maxn = 100 + 10;
int dp[3][maxn], arr[3][maxn], n;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= 2; i++)
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + arr[i][j];
		}
	cout << dp[2][n] << '\n';
	return 0;
}

