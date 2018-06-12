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
	int N; int K;
	while(~scanf("%d%d", &N, &K)) {
		int mask = 0;
		rep(i, K) {
			int D;
			scanf("%d", &D);
			mask |= 1 << D;
		}
		while(1) {
			int x = N;
			bool ok = true;
			do {
				ok &= ~mask >> (x % 10) & 1;
				x /= 10;
			} while(x);
			if(ok) break;
			++ N;
		}
		printf("%d\n", N);
	}
	return 0;
}
