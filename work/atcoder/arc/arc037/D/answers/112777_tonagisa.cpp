#include "bits/stdc++.h"

#define REP(i,n) for(ll i=0;i<n;++i)
#define RREP(i,n) for(ll i=n-1;i>=0;--i)
#define FOR(i,m,n) for(ll i=m;i<n;++i)
#define RFOR(i,m,n) for(ll i=n-1;i>=m;--i)
#define ALL(v) (v).begin(),(v).end()
#define PB(a) push_back(a)
#define DUMP(v) REP(i,(v).size()){cout<<v[i];if(i!=v.size()-1)cout<<" ";else cout<<endl;}
#define INF 1000000001ll
#define MOD 1000000007ll
#define EPS 1e-9

const int dx[8] = { 1,1,0,-1,-1,-1,0,1 };
const int dy[8] = { 0,1,1,1,0,-1,-1,-1 };

typedef long long ll;
using namespace std;

#define MAX_N 100
#define MAX_V 100
#define MAX_M 100
bool visited[MAX_N];
vector<vector<int>> g(MAX_N);
bool dfs(int i ,int p) {
	if (visited[i])return true;
	visited[i] = true;
	bool ret = false;
	REP(v, g[i].size()) {
		if (g[i][v]== p)continue;
		if (visited[g[i][v]]) ret = true;
		else ret |= dfs(g[i][v], i);
	}
	return ret;
}


int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	
	REP(i, m) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	int cnt = 0;
	REP(i, n) {
		if (!visited[i]) if (!dfs(i, -1))cnt++;
	}
	cout << cnt << endl;
	return 0;
}
