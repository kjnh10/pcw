#include <bits/stdc++.h>

typedef long long ll;
typedef long long llong;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;

/*
ll pw(ll a, ll b) {
	ll ans = 1; while (b) {
		while (!(b & 1)) b >>= 1, a = (a * a) % MOD;
		ans = (ans * a) % MOD, --b;
	} return ans;
}
*/
const int MAXN = 1200;
int n;
int av[5100];
vector<int> eds[MAXN];
int p[MAXN];
int x[MAXN];
vector<int> vv;
pair<int, int> dp[MAXN];

int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; ++i) {
		scanf("%d", p + i);
		--p[i];
		eds[p[i]].push_back(i);
	}
	for (int i = 0; i < n; ++i)
		scanf("%d", x + i);
	for (int i = n - 1; i >= 0; --i) {
		int sum = 0;
		vv.clear();
		int nd = x[i];
		for (int u: eds[i]) {
			sum += dp[u].first + dp[u].second;
			nd -= min(dp[u].first, dp[u].second);
			vv.push_back(abs(dp[u].first - dp[u].second));
		}
		if (nd < 0) {
			cout << "IMPOSSIBLE\n";
			return 0;
		}
		memset(av, 0, sizeof(av[0]) * (nd + 1));
		av[0] = 1;
		for (int i: vv) {
			for (int j = nd; j >= i; --j)
				if (av[j - i])
					av[j] = 1;
		}
		for (int j = nd; j >= 0; --j) {
			if (av[j]) {
				sum += nd - j;
				break;
			}
		}
		dp[i] = make_pair(x[i], sum - x[i]);
	}
	cout << "POSSIBLE\n";
	return 0;
}


