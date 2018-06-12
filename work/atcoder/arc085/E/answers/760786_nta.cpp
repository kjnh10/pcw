#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if (y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if (x < y) x = y; }
#define each(it,o) for(auto it = (o).begin(); it != (o).end(); ++ it)

struct MaximumFlow {
	typedef int Index;
	typedef ll Flow;
	static constexpr Flow InfCapacity = INFL;
	struct Edge {
		Index to;
		Flow capacity;
		Index rev;
	};
	vector<vector<Edge> > g;
	void init(Index n) { g.assign(n, vector<Edge>()); }
	void add(Index i, Index j, Flow capacity) {
		Edge e, f; e.to = j, f.to = i; e.capacity = capacity, f.capacity = 0;
		g[i].push_back(e); g[j].push_back(f);
		g[i].back().rev = (Index)g[j].size() - 1; g[j].back().rev = (Index)g[i].size() - 1;
	}
	void addB(Index i, Index j, Flow capacity) {
		Edge e, f; e.to = j, f.to = i; e.capacity = capacity, f.capacity = capacity;
		g[i].push_back(e); g[j].push_back(f);
		g[i].back().rev = (Index)g[j].size() - 1; g[j].back().rev = (Index)g[i].size() - 1;
	}
	//gを破壊する
	Flow maximumFlow(int s, int t) {
		int n = g.size();
		vector<Index> level(n);
		Flow total = 0; bool update;
		do {
			update = false;
			fill(level.begin(), level.end(), -1); level[s] = 0;
			queue<Index> q; q.push(s);
			for (Index d = n; !q.empty() && level[q.front()] < d; ) {
				int u = q.front(); q.pop();
				if (u == t) d = level[u];
				each(e, g[u]) if (e->capacity > 0 && level[e->to] == -1)
					q.push(e->to), level[e->to] = level[u] + 1;
			}
			vector<Index> iter(n);
			for (Index i = 0; i < n; i ++) iter[i] = (int)g[i].size() - 1;
			while (1) {
				Flow f = augment(level, iter, s, t, InfCapacity);
				if (f == 0) break;
				total += f; update = true;
			}
		} while (update);
		return total;
	}
	Flow augment(vector<Index> &level, vector<Index> &iter, Index u, Index t, Flow f) {
		if (u == t || f == 0) return f;
		Index lv = level[u];
		if (lv == -1) return 0;
		level[u] = -1;
		for (; iter[u] >= 0; -- iter[u]) {
			Edge &e = g[u][iter[u]];
			if (level[e.to] <= lv) continue;
			Flow l = augment(level, iter, e.to, t, min(f, e.capacity));
			if (l == 0) continue;
			e.capacity -= l; g[e.to][e.rev].capacity += l;
			level[u] = lv;
			return l;
		}
		return 0;
	}
};

int main() {
	int N;
	while (~scanf("%d", &N)) {
		vector<int> a(N);
		for (int i = 0; i < N; ++ i)
			scanf("%d", &a[i]);
		int src = N, dst = src + 1;
		MaximumFlow mf;
		mf.init(dst + 1);
		ll base = 0;
		rep(i, N) {
			int x = i + 1;
			for(int y = x * 2; y <= N; y += x)
				mf.add(i, y - 1, INFL);
			base += max(a[i], 0);
			if (a[i] > 0)
				mf.add(i, dst, a[i]);
			else
				mf.add(src, i, -a[i]);
		}
		ll flow = mf.maximumFlow(src, dst);
		ll ans = base - flow;
		printf("%lld\n", ans);
	}
	return 0;
}
