#include <bits/stdc++.h>  

using namespace std;

#define FOR(i, j, k) for(int i = j; i < k; ++i)
#define rep(i, j) FOR(i, 0, j)
#define repr(i, j) for(int i = j; i >= 0; --i)
#define INF (1 << 30)

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;

int n, k;
double r[101];
double ans = 0;
double now;

int main() {
	scanf("%d %d", &n, &k);
	rep(i, n) scanf("%lf", &r[i]);
	sort(r, r + n);
	FOR(i, n - k, n) {
		now = ans;
		ans = (now + r[i]) / 2.0;
	}
	printf("%.10f\n", ans);
	return 0;
}