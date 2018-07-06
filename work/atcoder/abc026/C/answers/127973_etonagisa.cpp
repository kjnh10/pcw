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

int dfs(vector<vector<int>> &g, int v) {
	vector<int> s;
	REP(i, g[v].size()) {
		s.push_back(dfs(g, g[v][i]));
	}
	sort(ALL(s));
	if (s.empty())return 1;
	else return 1 + s[0] + s[s.size() - 1];
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<vector<int>> g(n);
	REP(i, n - 1) {
		int b;
		cin >> b;
		g[b - 1].push_back(i + 1);
	}
	cout << dfs(g, 0) << endl;
	return 0;
}
