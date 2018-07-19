#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define MOD 1000000007
#define ADD(X,Y) ((X) = ((X) + (Y)%MOD) % MOD)
typedef long long i64; typedef vector<int> ivec; typedef vector<string> svec;

int N, K;
i64 dp[2020][2020];

int main()
{
	scanf("%d%d", &N, &K);
	if (N == 1) {
		puts("1");
		return 0;
	}
	--K;
	dp[0][N] = 1;
	for (int i = 2; i <= N; ++i) dp[1][i] = 1;
	for (int i = 1; i < K; ++i) {
		for (int j = N; j >= 2; --j) {
			ADD(dp[i + 1][(i + j == N + 1 ? (j - 1) : j)], dp[i][j]);
		}
		for (int j = N; j >= 2; --j) {
			ADD(dp[i + 1][j - 1], dp[i + 1][j]);
		}
	}
	i64 ret = 0;
	for (int i = 2; i <= N; ++i) ADD(ret, dp[K][i]);
	if (K != N - 1) {
		for (int i = 0; i < N - K - 2; ++i) ADD(ret, ret);
	}
	printf("%lld\n", ret);

	return 0;
}
