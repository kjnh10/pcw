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
	int H; int W;
	while(~scanf("%d%d", &H, &W)) {
		vector<string> S(H);
		rep(i, H)
			cin >> S[i];
		vector<string> T(H, string(W, '?'));
		rep(i, H) rep(j, W) {
			bool a = true;
			rer(dy, -1, 1) rer(dx, -1, 1) {
				int yy = i + dy, xx = j + dx;
				a &= yy < 0 || yy >= H || xx < 0 || xx >= W || S[yy][xx] == '#';
			}
			T[i][j] = a ? '#' : '.';
		}
		vector<string> U(H, string(W, '?'));
		rep(i, H) rep(j, W) {
			bool a = false;
			rer(dy, -1, 1) rer(dx, -1, 1) {
				int yy = i + dy, xx = j + dx;
				a |= !(yy < 0 || yy >= H || xx < 0 || xx >= W) && T[yy][xx] == '#';
			}
			U[i][j] = a ? '#' : '.';
		}
		if(S == U) {
			puts("possible");
			rep(i, H)
				puts(T[i].c_str());
		} else {
			puts("impossible");
		}
	}
	return 0;
}
