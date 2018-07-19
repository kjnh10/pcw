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
	int N; int A; int B;
	while (~scanf("%d%d%d", &N, &A, &B)) {
		vector<int> X(N);
		for (int i = 0; i < N; ++i)
			scanf("%d", &X[i]);
		ll ans = 0;
		rep(i, N - 1)
			ans += min((ll)A*(X[i + 1] - X[i]), (ll)B);
		printf("%lld\n", ans);
	}
	return 0;
}
