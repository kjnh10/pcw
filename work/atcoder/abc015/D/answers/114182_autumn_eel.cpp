#include<bits/stdc++.h>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;

int dp[51][55][15001], a[50], b[50];
int main() {
	int w, n, k; scanf("%d%d%d", &w, &n, &k);
	rep(i, n)scanf("%d%d", &a[i], &b[i]);
	rep(i, n)for (int j = 0; j <= i; j++)rep(k, 10001) {
		dp[i + 1][j][k] = max(dp[i + 1][j][k], dp[i][j][k]);
		dp[i + 1][j + 1][k + a[i]] = max(dp[i + 1][j + 1][k + a[i]], dp[i][j][k] + b[i]);
	}
	int Max = 0;
	rep(j, k + 1)rep(k, w + 1)Max = max(Max, dp[n][j][k]);
	printf("%d\n", Max);
}