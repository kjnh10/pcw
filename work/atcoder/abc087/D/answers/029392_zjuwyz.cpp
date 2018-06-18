#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct edge
{
	int u;
	int v;
	int d;
	edge() :u(0), v(0), d(0) {}
	edge(int _u, int _v, int _d) :u(_u), v(_v), d(_d){}
};

vector<edge> G[100010];
int x[100010];
int vis[100010];

bool bfs(int s)
{
	queue<int> q;
	q.push(s);
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		for (int j = 0; j < G[u].size(); j++)
		{
			int v = G[u][j].v;
			int d = G[u][j].d;
			if (!vis[v])
			{
				vis[v] = true;
				x[v] = x[u] + d;
				q.push(v);
			}
			else
			{
				if (x[v] != x[u] + d)
				{
					return false;
				}
			}
		}
	}
	return true;
}
int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int l, r, d;
		cin >> l >> r >> d;
		G[l].push_back(edge(l, r, d));
		G[r].push_back(edge(r, l, -d));
	}
	bool flag = true;
	for (int i = 1; i <= n; i++)
	{
		if (!vis[i])
		{
			flag = bfs(i);
		}
		if (!flag) break;
	}
	cout << (flag ? "Yes\n" : "No\n");
	//system("pause");
}