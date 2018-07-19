#include <bits/stdc++.h>

using namespace std;

#define FOR(i, j, k) for(int i = j; i < k; ++i)
#define rep(i, j) FOR(i, 0, j)
#define Rrep(i, j) for(int i = j; i >= 0; --i)
#define INF (1 << 30)

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;

int N, ng[3];
int dp[301];

int main() {
	scanf("%d", &N);
	rep(i, 3) scanf("%d", &ng[i]);
	dp[N] = 0;
	rep(i, 3) if(N == ng[i]) {
		printf("NO\n");
		return 0;
	}
	rep(i, N) dp[i] = INF;
	Rrep(i, N) {
		if(i == ng[0] || i == ng[1] || i == ng[2]) continue;
		FOR(j, 1, 4) dp[i - j] = min(dp[i] + 1, dp[i - j]);
	}
	printf("%s\n", (dp[0] <= 100) ? "YES" : "NO");
	return 0;
}