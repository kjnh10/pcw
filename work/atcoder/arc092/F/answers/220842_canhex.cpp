#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> g, ind;

vector<int> ord;

vector<bool> usd;
vector<vector<int>> gr;
vector<int> comp;
void ts(int u)
{
	if (usd[u])
		return;
	usd[u] = true;
	for (int v : g[u])
		ts(v);
	ord.push_back(u);
}

void scc(int u, int c)
{
	if (comp[u] != -1)
		return;
	comp[u] = c;
	for (int v : gr[u])
		scc(v, c);
}

int main()
{
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	g.resize(n);
	gr.resize(n);
	ind.resize(n);
	for (int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;
		--a, --b;
		g[a].push_back(b);
		gr[b].push_back(a);
		ind[a].push_back(i);
	}
	usd.resize(n);
	for (int i = 0; i < n; ++i)
		ts(i);
	reverse(ord.begin(), ord.end());
	comp.resize(n, -1);
	int c = 0;
	for (int x : ord)
	{
		if (comp[x] == -1)
			scc(x, c++);
	}
	vector<vector<int>> g1(c);
	for (int i = 0; i < n; ++i)
		for (int j : g[i])
			if (comp[i] != comp[j])
				g1[comp[i]].push_back(comp[j]);
	for (auto& x : g1)
	{
		//sort(x.begin(), x.end());
		//x.resize(unique(x.begin(), x.end()) - x.begin());
	}
	vector<vector<int>> cc(c);
	for (int i = 0; i < n; ++i)
		cc[comp[i]].push_back(i);
	vector<bool> diff(m);
	for (int i = 0; i < c; ++i)
	{
		vector<int> q;
		vector<int> cnt(c, 0), from(n, -1);
		cnt[i] = 2;
		from[i] = i;
		for (int j : g1[i])
			if (cnt[j] == 0)
				cnt[j] = 1, from[j] = j, q.push_back(j);
			else if (cnt[j] == 1)
				++cnt[j];
		for (int it = 0; it < q.size(); ++it)
		{
			int x = q[it];
			for (int y : g1[x])
			{
				if (cnt[y] == 2)
					continue;
				if (cnt[x] == 2)
					cnt[y] = 2, q.push_back(y);
				else if (cnt[y] == 1)
				{
					if (from[y] == from[x])
						continue;
					else
						cnt[y] = 2, q.push_back(y);
				}
				else 
					cnt[y] = 1, from[y] = from[x], q.push_back(y);
			}
		}
		for (int x : cnt)
			cerr << x << ' ';
		cerr << '\n';
		for (int i1 : cc[i])
			for (int j = 0; j < g[i1].size(); ++j)
				if (i != comp[g[i1][j]] && cnt[comp[g[i1][j]]] == 2)
					diff[ind[i1][j]] = true;
	}
	for (int i = 0; i < n; ++i)
	{
		vector<int> q;
		vector<int> cnt(n, 0), from(n, -1);
		cnt[i] = 2;
		from[i] = i;
		for (int j : g[i])
			cnt[j] = 1, from[j] = j, q.push_back(j);
		for (int it = 0; it < q.size(); ++it)
		{
			int x = q[it];
			for (int y : g[x])
			{
				if (cnt[y] == 2)
					continue;
				if (cnt[x] == 2)
					cnt[y] = 2, q.push_back(y);
				else if (cnt[y] == 1)
				{
					if (from[y] == from[x])
						continue;
					else
						cnt[y] = 2, q.push_back(y);
				}
				else 
					cnt[y] = 1, from[y] = from[x], q.push_back(y);
			}
		}
		for (int j = 0; j < g[i].size(); ++j)
			if (comp[i] == comp[g[i][j]] && cnt[g[i][j]] != 2)
				diff[ind[i][j]] = true;
	}
	for (int i = 0; i < m; ++i)
		if (diff[i])
			cout << "diff\n";
		else
			cout << "same\n";
}
