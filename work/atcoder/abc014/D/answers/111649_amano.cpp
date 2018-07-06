#include <bits/stdc++.h>
using namespace std;
#define FOR(i,k,n) for(int i = (int)(k); i < (int)(n); i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(a) a.begin(), a.end()
#define MS(m,v) memset(m,v,sizeof(m))
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> pii;
const int MOD = 1e9 + 7;
template<class T> T &chmin(T &a, const T &b) { return a = min(a, b); }
template<class T> T &chmax(T &a, const T &b) { return a = max(a, b); }
template<class T>
istream& operator >> (istream& is, vector<T>& v)
{
	for (auto &i : v) is >> i;
	return is;
}
template<class T>
ostream& operator<<(ostream& os, vector<T>& v)
{
	const string delimiter = "\n";
	REP(i, v.size())
	{
		os << v[i];
		if (i != v.size() - 1) os << delimiter;
	}
	return os;
}
/*--------------------template--------------------*/

typedef int Weight;
struct Edge
{
	int from, to; Weight cost;
	bool operator < (const Edge& e) const { return cost < e.cost; }
	bool operator > (const Edge& e) const { return cost > e.cost; }
};
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;
typedef vector<Weight> Array;
typedef vector<Array> Matrix;
void add_edge(Graph &g, int from, int to, Weight cost)
{
	g[from].push_back(Edge{ from, to, cost });
}


class LCA {
	int size, log_size;
	vector<vector<int>> parent;
	vector<int> depth;
	void dfs(const Graph &g, int v, int p, int d) {
		parent[0][v] = p; depth[v] = d;
		for (const Edge &e : g[v]) {
			if (e.to != p) dfs(g, e.to, v, d + 1);
		}
	}
public:
	LCA(const Graph &g, int root) : size(g.size()), log_size(0), depth(size, 0) {
		for (int v = size; v > 0; v /= 2) ++log_size;
		parent.assign(log_size, vector<int>(size, 0));
		dfs(g, root, -1, 0);
		for (int k = 0; k < log_size - 1; ++k) {
			for (int v = 0; v < size; ++v) {
				if (parent[k][v] < 0) parent[k + 1][v] = -1;
				else parent[k + 1][v] = parent[k][parent[k][v]];
			}
		}
	}
	int query(int u, int v) {
		if (depth[u] > depth[v]) swap(u, v);
		for (int k = 0; k < log_size; ++k)
			if (((depth[v] - depth[u]) >> k) & 1) v = parent[k][v];
		if (u == v) return u;
		for (int k = log_size - 1; k >= 0; k--) {
			if (parent[k][u] != parent[k][v]) {
				u = parent[k][u];
				v = parent[k][v];
			}
		}
		return parent[0][u];
	}
};


int main()
{
	cin.sync_with_stdio(false); cout << fixed << setprecision(10);
	int n; cin >> n;
	Graph g(n);
	REP(i, n - 1)
	{
		int a, b;
		cin >> a >> b;
		a--; b--;
		add_edge(g, a, b, 1);
		add_edge(g, b, a, 1);
	}
	Graph tree(n);
	vi depth(n, -1);
	depth[0] = 0;
	queue<int> que;
	que.push(0);
	while (!que.empty())
	{
		int v = que.front();
		que.pop();
		for (auto e : g[v])
		{
			int u = e.to;
			if (depth[u] >= 0) continue;
			depth[u] = depth[v] + 1;
			add_edge(tree, v, u, 1);
			que.push(u);
		}
	}
	LCA lca(tree, 0);
	int q; cin >> q;
	while (q--)
	{
		int a, b; cin >> a >> b;
		a--; b--;
		int c = lca.query(a, b);
		cout << depth[a] + depth[b] - 2 * depth[c] + 1 << endl;
	}
	return 0;
}