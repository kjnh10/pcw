#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int limit = 100010;
using edge = struct {int to; ll cost;};
vector<edge> tree[limit];
ll depth[limit];

void dfs(int v, int p, ll d) {
	depth[v] = d;
	for (auto &e : tree[v]) {
		if (e.to == p) continue;
		dfs(e.to, v, d + e.cost);
	}
}

int main(void) {
	int n;
	cin >> n;

	for (int i = 0; i < n - 1; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		a--, b--;
		tree[a].push_back({b, c});
		tree[b].push_back({a, c});
	}

	int q, k;
	cin >> q >> k;
	k--;

	dfs(k, -1, 0);
	for (int i = 0; i < q; ++i) {
		int x, y;
		cin >> x >> y;
		x--, y--;
		cout << depth[x] + depth[y] << endl;
	}

	return 0;
}