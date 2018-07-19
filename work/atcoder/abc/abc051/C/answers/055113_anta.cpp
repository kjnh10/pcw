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
	int sx; int sy; int tx; int ty;
	while (~scanf("%d%d%d%d", &sx, &sy, &tx, &ty)) {
		int x = tx - sx, y = ty - sy;
		string ans;
		rep(i, x)
			ans += 'R';
		rep(i, y)
			ans += 'U';
		rep(i, x)
			ans += 'L';
		rep(i, y)
			ans += 'D';
		ans += 'L';
		rep(i, y + 1)
			ans += 'U';
		rep(i, x + 1)
			ans += 'R';
		ans += 'D';
		ans += 'R';
		rep(i, y + 1)
			ans += 'D';
		rep(i, x + 1)
			ans += 'L';
		ans += 'U';
		puts(ans.c_str());
	}
	return 0;
}
