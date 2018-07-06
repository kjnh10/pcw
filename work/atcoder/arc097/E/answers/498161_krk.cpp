#include <bits/stdc++.h>
using namespace std;

const int Maxm = 4015;
const int Maxn = 2005;
const int Inf = 1000000000;

int n;
int pos[2][Maxn];
int BIT[Maxm];
int dp[Maxn][Maxn];

void Update(int ind, int val)
{
	for (int i = ind; i < Maxm; i += i & -i)
		BIT[i] += val;
}

int Get(int ind)
{
	int res = 0;
	for (int i = ind; i > 0; i -= i & -i)
		res += BIT[i];
	return res;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= 2 * n; i++) {
		char c; int a; scanf(" %c %d", &c, &a);
		pos[c == 'B'][a] = i;
	}
	fill((int*)dp, (int*)dp + Maxn * Maxn, Inf);
	dp[0][0] = 0;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			if (i + 1 <= n) {
				int add = pos[0][i + 1] - 1 - Get(pos[0][i + 1]);
				dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + add);
			}
			if (j + 1 <= n) {
				int add = pos[1][j + 1] - 1 - Get(pos[1][j + 1]);
				dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + add);
				Update(pos[1][j + 1], 1);
			}
		}
		for (int j = 1; j <= n; j++)
			Update(pos[1][j], -1);
		if (i + 1 <= n) Update(pos[0][i + 1], 1);
	}
	printf("%d\n", dp[n][n]);
	return 0;
}