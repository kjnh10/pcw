#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if (y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if (x < y) x = y; }

int main() {
	int N; int M;
	while (~scanf("%d%d", &N, &M)) {
		vector<vector<int> > g(N);
		for (int i = 0; i < M; ++ i) {
			int u, v;
			scanf("%d%d", &u, &v), -- u, -- v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		bool ans = false;
		reu(i, 1, N - 1) {
			bool a = false, b = false;
			for (int j : g[i]) {
				a |= j == 0;
				b |= j == N - 1;
			}
			ans |= a && b;
		}
		puts(ans ? "POSSIBLE" : "IMPOSSIBLE ");
	}
	return 0;
}
