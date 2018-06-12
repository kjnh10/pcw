#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using ii = pair<ll, ll>;
using vi = vector<ll>;
using vb = vector<bool>;
using vvi = vector<vi>;
using vii = vector<ii>;
using vvii = vector<vii>;

constexpr int INF = 2000000000;
constexpr ll LLINF = 9000000000000000000;

template<typename F>	// All subsets of set
void iterate_mask_subset(ll set, F f){ ll mask = set;
	do  f(mask), mask = (mask-1) & set;
	while (mask != set);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, m;
	cin >> n >> m;
	vvi C(n, vi(n, 0LL));
	while (m--) {
		int a, b, c; cin >> a >> b >> c; --a; --b;
		C[a][b] = C[b][a] = c;
	}

	// Minimum connector
	int all = (1<<n) - 1;
	vi ic(1<<n, 0LL);
	vvi dp(n, vi(1<<n, -1LL));
	dp[0][1<<0] = 0LL;
	for (int mask = 0; mask < (1<<n); ++mask) {
		for (int u = 0; u < n; ++u)
			for (int v = u+1; v < n; ++v)
				if (((mask>>v)&1) && ((mask>>u)&1)) ic[mask] += C[u][v];
	}
	for (int mask = 0; mask < (1<<n); ++mask) {
		int submask = (all&~mask);
		do {
			for (int u = 0; u < n; ++u) {
				if (!((mask>>u)&1)) continue;
				if (dp[u][mask] < 0LL) continue;
				ll nc = dp[u][mask] + ic[submask|(1<<u)];
				if (nc > dp[u][mask|submask])
					dp[u][mask|submask] = nc;
			}
			submask = (submask - 1) & (all&~mask);
		} while (submask != (all&~mask));
		for (int u = 0; u < n; ++u) {
			if (!((mask>>u)&1)) continue;
			if (dp[u][mask] < 0LL) continue;
			for (int v = 0; v < n; ++v) {
				if ((mask>>v)&1) continue;
				if (C[u][v] == 0LL) continue;
				ll nc = dp[u][mask] + C[u][v];
				if (nc > dp[v][mask|(1<<v)])
					dp[v][mask|(1<<v)] = nc;
			}
		}
	}

	ll ans = 0LL;
	for (vi &c : C) for (ll v : c) ans += v;
	ans = (ans / 2) - dp[n - 1][all];
	cout << ans << endl;

	return 0;
}
