#include <bits/stdc++.h>

using namespace std;

#define FOR(i, j, k) for(int i = j; i < k; ++i)
#define rep(i, j) FOR(i, 0, j)
#define repr(i, j) for(int i = j; i >= 0; --i)
#define INF (1 << 30)
#define MOD 1000000007

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;

int n;
int ng1, ng2, ng3;
int dp[110];

int main() {
	scanf("%d %d %d %d", &n, &ng1, &ng2, &ng3);
	if(n == ng1 || n == ng2 || n == ng3) {
		printf("NO\n");
		return 0;
	}
	rep(i, n) dp[i] = INF;
	dp[n] = 0;
	repr(i, n) {
		if(i == ng1 || i == ng2 || i == ng3) continue;
		FOR(j, 1, 4) dp[i-j] = min(dp[i] + 1, dp[i - j]);
	}
	printf("%s\n", (dp[0] <= 100) ? "YES" : "NO");
	return 0;
}