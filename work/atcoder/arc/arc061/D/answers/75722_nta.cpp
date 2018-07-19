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
	int H; int W; int N;
	while(~scanf("%d%d%d", &H, &W, &N)) {
		vpii colored;
		vpii poses;
		rep(i, N) {
			int y; int x;
			scanf("%d%d", &y, &x), -- y, -- x;
			colored.emplace_back(y, x);
			rer(dy, -1, 1) rer(dx, -1, 1) {
				int yy = y + dy, xx = x + dx;
				if(0 < yy && yy < H - 1 && 0 < xx && xx < W - 1)
					poses.emplace_back(yy, xx);
			}
		}
		sort(colored.begin(), colored.end());
		sort(poses.begin(), poses.end());
		poses.erase(unique(poses.begin(), poses.end()), poses.end());
		ll ans[10] = {};
		for(auto p : poses) {
			int j = 0;
			rer(dy, -1, 1) rer(dx, -1, 1) {
				pii q{ p.first + dy, p.second + dx };
				j += binary_search(colored.begin(), colored.end(), q);
			}
			++ ans[j];
		}
		ans[0] += (ll)(H - 2) * (W - 2) - poses.size();
		for(int i = 0; i < 10; ++ i)
			printf("%lld\n", ans[i]);
	}
	return 0;
}
