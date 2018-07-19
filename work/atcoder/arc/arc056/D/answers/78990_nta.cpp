#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if(x < y) x = y; }

struct UnionFind {
	vector<int> data;
	void init(int n) { data.assign(n, -1); }
	bool unionSet(int x, int y) {
		x = root(x); y = root(y);
		if(x != y) {
			if(data[y] < data[x]) swap(x, y);
			data[x] += data[y]; data[y] = x;
		}
		return x != y;
	}
	bool findSet(int x, int y) { return root(x) == root(y); }
	int root(int x) { return data[x] < 0 ? x : data[x] = root(data[x]); }
	int size(int x) { return -data[root(x)]; }
};

int main() {
	int N; int M; int S;
	while(~scanf("%d%d%d", &N, &M, &S)) {
		-- S;
		vector<vector<int> > g(N);
		for(int i = 0; i < M; ++ i) {
			int u, v;
			scanf("%d%d", &u, &v), -- u, -- v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		UnionFind uf; uf.init(N);
		vector<int> ans;
		for(int i = N - 1; i >= 0; -- i) {
			for(int j : g[i]) if(j >= i)
				uf.unionSet(i, j);
			if(uf.findSet(i, S))
				ans.push_back(i);
		}
		reverse(ans.begin(), ans.end());
		for(int i = 0; i < (int)ans.size(); ++ i)
			printf("%d\n", ans[i] + 1);
	}
	return 0;
}
