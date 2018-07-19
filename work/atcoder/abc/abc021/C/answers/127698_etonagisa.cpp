#include "bits/stdc++.h"

#define REP(i,n) for(ll i=0;i<n;++i)
#define RREP(i,n) for(ll i=n-1;i>=0;--i)
#define FOR(i,m,n) for(ll i=m;i<n;++i)
#define RFOR(i,m,n) for(ll i=n-1;i>=m;--i)
#define ALL(v) (v).begin(),(v).end()
#define PB(a) push_back(a)
#define UNIQUE(v) v.erase(unique(ALL(V),v.end()));
#define DUMP(v) REP(i, (v).size()) { cout << v[i]; if (i != v.size() - 1)cout << " "; else cout << endl; }
#define INF 1000000001ll
#define MOD 1000000007ll
#define EPS 1e-9

const int dx[8] = { 1,1,0,-1,-1,-1,0,1 };
const int dy[8] = { 0,1,1,1,0,-1,-1,-1 };

typedef long long ll;
using namespace std;
int a, b;
int dp[100];
int bfs(vector<vector<int>> &g, vector<vector<int>> &dist, int v,int p) {
	if (dp[v] != -1)return dp[v];
	int ret = 0;
	
	REP(i, g[v].size()) {
		if (g[v][i] == p)continue;
		if (dist[a][g[v][i]] == dist[a][v] - 1) ret = (ret+bfs(g, dist, g[v][i],v))%MOD;
	}
	return dp[v] = ret;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> a >> b >> m;
	a--; b--;
	vector<vector<int>> g(n);
	vector<vector<int>> dist(n, vector<int>(n, INF));
	REP(i, m) {
		int x, y;
		cin >> x >> y;
		x--; y--;
		g[x].push_back(y);
		g[y].push_back(x);
		dist[x][y] = 1;
		dist[y][x] = 1;
	}
	REP(k, n) {
		REP(i, n) {
			REP(j, n) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	REP(i, n)dp[i] = -1;
	dp[a] = 1;
	dist[a][a] = 0;
	cout << bfs(g, dist, b,-1) << endl;
	return 0;
}
