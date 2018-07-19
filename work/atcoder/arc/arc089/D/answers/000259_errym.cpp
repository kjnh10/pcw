#include <bits/stdc++.h>
using namespace std;

int cnt[4005][4005];
int n, k, ans;

int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 0;i < n;i++)
	{
		int x, y; char c; scanf("%d%d %c", &x, &y, &c);
		if (c == 'B') y += k;
		x %= (2*k); y %= (2*k);
		cnt[x][y]++;
	}
	for (int i = 0;i < 2*k;i++) for (int j = 0;j < 2*k;j++) cnt[i+2*k][j] = cnt[i][j+2*k] = cnt[i+2*k][j+2*k] = cnt[i][j];
	for (int i = 0;i < 4*k;i++) for (int j = 0;j < 4*k;j++) cnt[i][j] += (i?cnt[i-1][j]:0)+(j?cnt[i][j-1]:0)-(i&&j?cnt[i-1][j-1]:0);
	for (int i = 0;i < 2*k;i++) for (int j = 0;j < 2*k;j++) ans = max(ans, cnt[i+2*k][j+2*k]-cnt[i+k][j+2*k]-cnt[i+2*k][j+k]+cnt[i+k][j+k]+cnt[i+k][j+k]-cnt[i][j+k]-cnt[i+k][j]+cnt[i][j]);
	printf("%d\n", ans);
	return 0;
}
