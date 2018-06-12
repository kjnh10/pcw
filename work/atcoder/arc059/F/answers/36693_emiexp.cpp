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

int N, L;
char S[5050];
unsigned int dp[5050][5050];
int C[5050][5050];

int main()
{
	scanf("%d%s", &N, S);
	L = strlen(S);

	dp[0][0] = 1;
	for (int i = 0; i <= N; ++i) {
		for (int j = 0; j <= i; ++j) {
			if (i == 0 && j == 0) continue;
			dp[i][j] = ((i > 0 ? dp[i - 1][j] : 0) + (j > 0 ? (2 * dp[i][j - 1]) : 0)) % MOD;
		//	printf("%d %d %lld\n", i, j, dp[i][j]);
		}
	}
	C[0][0] = 1;
	for (int i = 1; i <= N; ++i) {
		C[i][0] = 1;
		for (int j = 1; j <= N; ++j) {
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
		}
	}

	i64 ans = 0;
	for (int i = 0; L + 2 * i <= N; ++i) {
		i64 tmp = dp[L + i - 1][i];
		//for (int j = 0; j < i; ++j) tmp = tmp * 2 % MOD;
		i64 tmp2 = 0;

		int rem = N - (L + 2 * i);
		for (int b = 0; b <= rem; ++b) {
			int c = rem - b;
			if (c <= b) ADD(tmp2, dp[b][c]);
		}
	//	printf("%d %d: %lld %lld\n", i, rem, tmp, tmp2);
		ADD(ans, tmp * tmp2);
	}
	printf("%lld\n", ans);

	return 0;
}
