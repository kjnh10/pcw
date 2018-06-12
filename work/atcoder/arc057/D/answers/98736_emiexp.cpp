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
#include <cmath>
#include <map>
using namespace std;
#define MOD 1000000007
#define ADD(X,Y) ((X) = ((X) + (Y)%MOD) % MOD)
typedef long long i64; typedef vector<int> ivec; typedef vector<string> svec;

int N, K;
int A[2020];
i64 dp[2020][2020];
i64 dpmax[2020][2020];

i64 rup(i64 a, i64 b)
{
	return a / b + 1;
}
i64 rupdw(i64 a, i64 b)
{
	return a / b;
}


int main()
{
	scanf("%d%d", &N, &K);
	for (int i = 0; i < N; ++i) scanf("%d", A + i);
	dp[0][0] = 0;
	dpmax[0][0] = 0;
	for (int i = 1; i <= N; ++i) {
		dp[0][i] = K + 10;
		dpmax[0][i] = -K;
	}

	i64 S = 0;
	for (int i = 0; i <= N; ++i) {
		for (int j = 0; j <= N; ++j) {
			dp[i + 1][j] = K + 10;
			dpmax[i + 1][j] = -K;
		}
		for (int j = 0; j <= N; ++j) {
			dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);

			i64 req2 = 0;
			if (i > 0) req2 = rupdw(dpmax[i][j] * A[i], S);
			req2 = min(req2, (i64)A[i]);
			dpmax[i + 1][j] = max(dpmax[i + 1][j], dpmax[i][j] + req2);

			i64 req = 0;
			if (i == 0) req = 1;
			else req = rup(dp[i][j] * A[i], S);

			if (req > A[i]) req = K + 10;
			dp[i + 1][j + 1] = min(dp[i + 1][j + 1], dp[i][j] + req);
			if (i == 0 || dpmax[i][j] != S) dpmax[i + 1][j + 1] = max(dpmax[i + 1][j + 1], dpmax[i][j] + A[j]);
		//	printf("%lld/%lld ", dp[i][j], dpmax[i][j]);
		}
	//	puts("");
		S += A[i];
	}
	/*for (int i = 0; i <= N; ++i) {
		for (int j = 0; j <= N; ++j) printf("%lld/%lld ", dp[i][j], dpmax[i][j]);
		puts("");
	}*/
	int sum = 0;
	for (int i = 0; i < N; ++i) sum += A[i];
	if (sum == K) {
		puts("1");
		return 0;
	}
	if (sum == K - 1) {
		if (A[0] == 1) printf("%d\n", N - 1);
		else printf("%d\n", N);
		return 0;
	}

	for (int i = N; i >= 0; --i) {
		if (dp[N][i] <= K) {
			printf("%d\n", i); break;
		}
	}

	return 0;
}
