#include <bits/stdc++.h>
using namespace std;

const long long inf = 1e18;

struct ShortestPath {
	struct edge { int to; long long cost; };
	vector<vector<edge>> g;
	ShortestPath(int n) : g(n) {}
	void add(int u, int v, long long cost) { g[u].push_back({ v, cost }); }
	vector<long long> shortest(int s) {
		vector<long long> dist(g.size(), inf);
		priority_queue<pair<long long, int>> q;
		dist[s] = 0;
		q.emplace(0, s);
		while (!q.empty()) {
			long long d;
			int curr;
			tie(d, curr) = q.top(); q.pop();
			if (dist[curr] < -d) continue;
			for (edge e : g[curr]) if (dist[e.to] > dist[curr] + e.cost) {
				dist[e.to] = dist[curr] + e.cost;
				q.emplace(-dist[e.to], e.to);
			}
		}
		return dist;
	}
	long long shortest(int s, int t) { return shortest(s)[t]; }
};

int main() {
	int n, m;
	long long t;
	cin >> n >> m >> t;

	vector<long long> a(n);
	for (int i = 0; i < n; i++) scanf("%lld", &a[i]);

	ShortestPath sp(n), sp2(n);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		a--; b--;
		sp.add(a, b, c);
		sp2.add(b, a, c);
	}

	auto dist = sp.shortest(0);
	auto dist2 = sp2.shortest(0);

	long long ans = 0;
	for (int i = 0; i < n; i++) {
		long long x = t - dist[i] - dist2[i];
		if (x < 0) continue;
		ans = max(ans, x * a[i]);
	}
	cout << ans << endl;
}