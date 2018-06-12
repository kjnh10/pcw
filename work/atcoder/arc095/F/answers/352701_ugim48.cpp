#include <bits/stdc++.h>
using namespace std;

#define rep(i, N) for (int i = 0; i < N; i++)
#define pb push_back

typedef long long ll;
typedef pair<int, int> i_i;
typedef pair<double, int> d_i;

vector<int> bfs(int N, vector<vector<int> >& G, int s) {
	vector<int> d(N, INT_MAX); d[s] = 0;
	queue<int> q; q.push(s);
	while (q.size()) {
		int u = q.front(); q.pop();
		for (int v: G[u])
			if (d[v] > d[u] + 1) {
				d[v] = d[u] + 1;
				q.push(v);
			}
	}
	return d;
}

void dfs_h(int u, int p, vector<vector<int>>& G, vector<int>& h) {
	for (int v: G[u]) if (v != p) dfs_h(v, u, G, h), h[u] = max(h[u], h[v] + 1);
}

int unko = 0;

void dfs_ans(int u, int p, vector<vector<int>>& G, vector<int>& h, vector<int>& ans) {
	int x = -1, y = -1;
	for (int v: G[u]) if (v != p) {
		if (h[v]) {
			if (x != -1) {
				cout << -1 << endl;
				exit(0);
			}
			x = v;
		}
		y = v;
	}
	if (x == -1) x = y;
	if (x != -1) dfs_ans(x, u, G, h, ans);
	int cnt = 0;
	for (int v: G[u]) if (v != p && v != x) cnt++;
	ans.pb(unko + cnt);
	for (int v: G[u]) if (v != p && v != x) ans.pb(unko++);
	unko++;
}

vector<int> solve(int N, vector<vector<int>> G) {
	vector<int> d0 = bfs(N, G, 0);
	int x = 0;
	rep(u, N) if (d0[u] > d0[x]) x = u;
	vector<int> dx = bfs(N, G, x);
	int y = 0;
	rep(u, N) if (dx[u] > dx[y]) y = u;
	vector<int> rs = {x, y};
	vector<int> P = {INT_MAX};
	for (int r: rs) {
		vector<int> h(N);
		dfs_h(r, -1, G, h);
		vector<int> ans;
		unko = 0;
		dfs_ans(r, -1, G, h, ans);
		vector<int> p(N);
		rep(t, N) p[ans[t]] = t;
		P = min(P, p);
	}
	return P;
}

int main() {
	int N; cin >> N;
	vector<vector<int>> G(N);
	rep(i, N - 1) {
		int u, v; scanf("%d%d", &u, &v), u--, v--;
		G[u].pb(v), G[v].pb(u);
	}
	vector<int> p = solve(N, G);
	if (p.empty()) cout << -1 << endl;
	else {
		for (int x: p) printf("%d ", x + 1);
		cout << endl;
	}
}
