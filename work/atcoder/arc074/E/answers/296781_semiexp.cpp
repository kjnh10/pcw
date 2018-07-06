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

int N, M;
int dp[303][303][303];
vector<pair<int, int> > cond[330];
int lo[330][3], hi[330][3];

int main()
{
	scanf("%d%d", &N, &M);
	for (int i = 0; i <= N; ++i) {
		for (int j = 0; j < 3; ++j) {
			lo[i][j] = 1000;
			hi[i][j] = -1;
		}
	}
	for (int i = 0; i < M; ++i) {
		int l, r, x;
		scanf("%d%d%d", &l, &r, &x);
		cond[r].push_back({ l, x });

		lo[r][x - 1] = min(lo[r][x - 1], l);
		hi[r][x - 1] = max(hi[r][x - 1], l);
	}
	dp[0][0][0] = 1;
	int ret = 0;
	for (int i = 0; i <= N; ++i) {
		for (int j = 0; j <= N; ++j) {
			for (int k = 0; k <= N; ++k) {
				int mx = max({ i, j, k });

				int snd, thrd;
				if (i == mx) {
					snd = max(j, k);
					thrd = min(j, k);
				} else if (j == mx) {
					snd = max(i, k);
					thrd = min(i, k);
				} else {
					snd = max(i, j);
					thrd = min(i, j);
				}
				if (hi[mx][2] > thrd) goto fail;
				if (lo[mx][1] <= thrd) goto fail;
				if (hi[mx][1] > snd) goto fail;
				if (lo[mx][0] <= snd) goto fail;


				if (mx == N) ADD(ret, dp[i][j][k]);
				else {
					++mx;
					ADD(dp[mx][j][k], dp[i][j][k]);
					ADD(dp[i][mx][k], dp[i][j][k]);
					ADD(dp[i][j][mx], dp[i][j][k]);
				}
			fail:
				dp[i][j][k] = 0;
			}
		}
	}
	printf("%d\n", ret);

	return 0;
}
