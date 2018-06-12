#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if(x < y) x = y; }

int main() {
	int N; int M;
	while(~scanf("%d%d", &N, &M)) {
		vector<vi> companies(N);
		vector<pair<pii, int>> edges;
		rep(i, M) {
			int p; int q; int c;
			scanf("%d%d%d", &p, &q, &c), -- p, -- q, -- c;
			companies[p].push_back(c);
			companies[q].push_back(c);
			edges.emplace_back(make_pair(p, c), q);
		}
		vector<int> offset(N + 1);
		offset[0] = N;
		rep(i, N) {
			vi &v = companies[i];
			sort(v.begin(), v.end());
			v.erase(unique(v.begin(), v.end()), v.end());
			offset[i + 1] = offset[i] + v.size();
		}
		vector<vi> graph(offset[N]);
		rep(i, N) {
			reu(j, offset[i], offset[i + 1])
				graph[j].push_back(i);
		}
		for(auto e : edges) {
			int u, c, v;
			tie(u, c) = e.first;
			v = e.second;
			int x = offset[u] + (int)(lower_bound(companies[u].begin(), companies[u].end(), c) - companies[u].begin());
			int y = offset[v] + (int)(lower_bound(companies[v].begin(), companies[v].end(), c) - companies[v].begin());
			graph[x].push_back(y);
			graph[y].push_back(x);
		}
		vector<bool> vis(offset[N]);
		vi q, nq;
		nq.push_back(0);
		int ans = -1;
		for(int d = 0; !nq.empty(); ++ d) {
			q.swap(nq);
			while(!q.empty()) {
				int i = q.back(); q.pop_back();
				if(vis[i]) continue;
				vis[i] = true;
				if(i == N - 1) {
					ans = d;
					nq.clear();
					break;
				}
				if(i < N) {
					reu(j, offset[i], offset[i + 1])
						nq.push_back(j);
				} else {
					for(int j : graph[i])
						q.push_back(j);
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
