#include <bits/stdc++.h>

using namespace std;

#define FOR(i, j, k) for(int i = j; i < k; ++i)
#define rep(i, j) FOR(i, 0, j)
#define Rrep(i, j) for(int i = j; i >= 0; --i)
#define INF (1 << 30)

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;

int main() {
	int n;
	vector<int> table(1000001);
	scanf("%d", &n);
	rep(i, n) {
		int a, b;
		scanf("%d %d", &a, &b);
		++table[a];
		--table[b + 1];
	}
	int ans = 0;
	rep(i, 1000000) table[i + 1] = table[i] + table[i + 1];
	rep(i, 1000001) ans = max(ans, table[i]);
	printf("%d\n", ans);
	return 0;
}