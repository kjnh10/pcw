#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int MOD = (int)1e9 + 7;
int add(int x, int y)
{
	x += y;
	if (x >= MOD) return x - MOD;
	return x;
}

const int N = 43;
const int M = (1 << 17) + 10;
int n, x, y, z;
int dp[N][M];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	scanf("%d%d%d%d", &n, &x, &y, &z);
	int ansMask = (1 << (z - 1)) + (1 << (y + z - 1)) + (1 << (x + y + z - 1));
	int m = 1 << (x + y + z);
	dp[0][0] = 1;
	for (int i = 0; i < n; i++)
		for (int mask = 0; mask <= m; mask++)
		{
			if (dp[i][mask] == 0) continue;
			for (int p = 1; p <= 10; p++)
			{
				if (mask == m)
				{
					dp[i + 1][m] = add(dp[i + 1][m], dp[i][m]);
					continue;
				}
				int nmask = ((mask << p) | (1 << (p - 1))) & (m - 1);
				if ((nmask & ansMask) == ansMask) nmask = m;
				dp[i + 1][nmask] = add(dp[i + 1][nmask], dp[i][mask]);
			}
		}
	printf("%d\n", dp[n][m]);

	return 0;
}