#include <bits/stdc++.h>  

using namespace std;

#define FOR(i, j, k) for(int i = j; i < k; ++i)
#define rep(i, j) FOR(i, 0, j)
#define repr(i, j) for(int i = j; i >= 0; -i)
#define INF (1 << 30)

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;

#define MAX_A 1000
#define MAX_B 1000
 
int A, B, a[MAX_A], b[MAX_B];
int dp[MAX_A + 1][MAX_B + 1];

int solve(int x, int y, int f) {
	if(x == A && y == B) return 0;
	if(dp[x][y] >= 0) return dp[x][y];

	int ret;
	if(f) {
		ret = INF;
		if(x < A) ret = min(ret, solve(x + 1, y, 0));
		if(y < B) ret = min(ret, solve(x, y + 1, 0));
	}
	else {
		ret = 0;
		if(x < A) ret = max(ret, solve(x + 1, y, 1) + a[x]);
		if(y < B) ret = max(ret, solve(x, y + 1, 1) + b[y]);
	}
	return (dp[x][y] = ret);
}

int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%d %d", &A, &B);
	rep(i, A) scanf("%d", &a[i]);
	rep(i, B) scanf("%d", &b[i]);
	//dp[0][0] = 0;
	printf("%d\n", solve(0, 0, 0));
	return 0;
}