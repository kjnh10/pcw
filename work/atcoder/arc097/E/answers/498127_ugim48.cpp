#include <bits/stdc++.h>
using namespace std;

#define rep(i, N) for (int i = 0; i < N; i++)
#define pb push_back

typedef long long ll;

vector<vector<int>> f(vector<int> a, vector<int> b) {
	int N = a.size();
	vector<vector<int>> c(N, vector<int>(N + 1));
	rep(x, N) rep(y, N) c[x][y + 1] = c[x][y] + (a[x] < b[y]);
	return c;
}

int main() {
	int N; cin >> N;
	vector<int> a(N), b(N);
	rep(t, N * 2) {
		string s; cin >> s;
		int i; cin >> i, i--;
		if (s == "W") a[i] = t;
		if (s == "B") b[i] = t;
	}
	vector<vector<int>> aa = f(a, a), ab = f(a, b), ba = f(b, a), bb = f(b, b);
	vector<vector<int>> dp(N + 1, vector<int>(N + 1, INT_MAX));
	dp[0][0] = 0;
	rep(x, N + 1) rep(y, N + 1) {
		if (x < N) dp[x + 1][y] = min(dp[x + 1][y], dp[x][y] + aa[x][x] + ab[x][y]);
		if (y < N) dp[x][y + 1] = min(dp[x][y + 1], dp[x][y] + bb[y][y] + ba[y][x]);
	}
	cout << dp[N][N] << endl;
}
