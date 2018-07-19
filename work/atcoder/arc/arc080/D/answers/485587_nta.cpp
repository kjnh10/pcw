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
	int H; int W;
	while (~scanf("%d%d", &H, &W)) {
		int N;
		scanf("%d", &N);
		vector<int> colors(H * W);
		int K = 0;
		for (int i = 0; i < N; ++ i) {
			int A;
			scanf("%d", &A);
			rep(k, A)
				colors[K ++] = i + 1;
		}
		vector<vi> ans(H, vi(W));
		{
			int k = 0;
			rep(i, H) rep(jj, W) {
				int j = i % 2 == 0 ? jj : W - 1 - jj;
				ans[i][j] = colors[k ++];
			}
		}
		rep(i, H) {
			for (int j = 0; j < W; ++ j) {
				if (j != 0) putchar(' ');
				printf("%d", ans[i][j]);
			}
			puts("");
		}
	}
	return 0;
}
