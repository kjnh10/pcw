#include <bits/stdc++.h>
using namespace std;
#define MAXN 100009
#define MAXM 30001
#define MOD 1000000007
#define INF 1000000009
#define EPS 1e-7
#define FOR(x,n) for(int x=0; x<n; x++)
#define FOR1e(x,n) for(int x=1; x<=n; x++)
#define pb push_back
#define all(x) x.begin(), x.end()
typedef pair<int, int> ii;
typedef long long ll;

vector<int> sons[55];
int p[55], m[55];
ll sz[55], cost[55];

void dfs(int u) {
	sz[u] = 1;
	cost[u] = m[u];

	FOR(i, sons[u].size()) {
		int v = sons[u][i];
		dfs(v);
		sz[u] += sz[v];
		cost[u] += cost[v];
	}
}

struct item {
	ll m, cost, rem;
	bool operator < (const item& a) const {
		return m*a.cost > cost*a.m;
	}
};

item greedy[55];

ll kp[55*55*55];

int main() {
	int n, x, d;
	scanf("%d %d %d", &n, &x, &d);
	scanf("%d", &m[1]);
	for (int i = 2; i <= n; i++) {
		scanf("%d %d", &m[i], &p[i]);
		sons[p[i]].pb(i);
	}
	dfs(1);

	for (int i = 1; i <= n; i++) {
		ll rem = 0;
		if (i == 1) rem = x;
		else rem = d - min(n, d);

		greedy[i-1].m = sz[i]; greedy[i-1].cost = cost[i]; greedy[i-1].rem = rem;
	}
	sort(greedy, greedy + n);
//	for (int i = 0; i < n; i++) printf("%lld %lld\n", greedy[i].m, greedy[i].cost);

	for (int profit = 1; profit <= n*n*n; profit++) kp[profit] = INF;

	for (int i = 1; i <= 1; i++) {
		for (int profit = n*n*n; profit >= 0; profit--) {
			for (int b = 1; b <= n && cost[i]*b <= x && sz[i]*b <= profit; b++) {
				kp[profit] = min(kp[profit], kp[profit - sz[i]*b] + cost[i]*b);
			}
		}
	}
	for (int i = 2; i <= n; i++) {
		for (int profit = n*n*n; profit >= 0; profit--) {
			for (int b = 1; b <= min(n, d) && cost[i]*b <= x && sz[i]*b <= profit; b++) {
				kp[profit] = min(kp[profit], kp[profit - sz[i]*b] + cost[i]*b);
			}
		}
	}

	ll ans = 0;
	for (int profit = n*n*n; profit >= 0; profit--) {
		if (kp[profit] > x) continue;
	//	printf("%d %lld\n", profit, kp[profit]);
		ll acum = profit, rem = x - kp[profit];
		for (int i = 0; i < n; i++) {
			if (rem == 0) break;
			acum += greedy[i].m* min(greedy[i].rem, rem/greedy[i].cost);
			rem -= greedy[i].cost*min(greedy[i].rem, rem/greedy[i].cost);
		}
		ans = max(ans, acum);
	}
	printf("%lld\n", ans);
}
