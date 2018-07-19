#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> g[100000];
vector<int> path, mem;
vector<int> col;

void dfs1(int v, int p) {
	path.push_back(v);
	if(v == n - 1) mem = path;
	for(int to : g[v])
		if(to != p) dfs1(to, v);
	path.pop_back();
}

void dfs2(int v, int c) {
	for(int to : g[v])
		if(col[to] == -1)
			col[to] = c, dfs2(to, c);
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n;
	for(int i = 0; i < n - 1; i++) {
		int u, v; cin >> u >> v; --u; --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs1(0, -1);
	col.assign(n, -1);
	int sz = mem.size();
	for(int i = 0; i < (sz + 1) / 2; i++) col[mem[i]] = 0;
	for(int i = (sz + 1) / 2; i < sz; i++) col[mem[i]] = 1;
	for(int i = 0; i < sz; i++) dfs2(mem[i], col[mem[i]]);
	int dif = 0;
	for(int i = 0; i < n; i++) dif += (col[i] == 0 ? 1 : -1);
	cout << (dif > 0 ? "Fennec" : "Snuke");
}