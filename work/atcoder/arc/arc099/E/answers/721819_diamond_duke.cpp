#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <utility>
#include <cstdio>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <cmath>
#include <set>
#include <map>
#define my_abs(x) ((x) < 0 ? -(x) : (x))
#define mp std::make_pair
#define pb push_back
typedef long long ll; 
int col[705], w, b; 
bool dp[705][705], app[705][705]; 
std::pair<int, int> arr[705]; 
std::vector<int> adj[705]; 
void dfs(int u, int c)
{
	if (~col[u])
	{
		if (col[u] != c)
		{
			puts("-1"); 
			exit(0); 
		}
		return; 
	}
	col[u] = c; 
	(c ? w : b)++; 
	for (int v : adj[u])
		dfs(v, c ^ 1); 
}
int main()
{
	// freopen("ARC099-E.in", "r", stdin); 
	memset(col, -1, sizeof(col)); 
	int n, m, len = 0; 
	scanf("%d%d", &n, &m); 
	for (int i = 0; i < m; i++)
	{
		int u, v; 
		scanf("%d%d", &u, &v); 
		u--; 
		v--;
		app[u][v] = app[v][u] = true; 
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!app[i][j] && i != j)
				adj[i].pb(j); 
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (~col[i])
			continue; 
		w = 0;
		b = 0; 
		dfs(i, 0); 
		arr[len++] = {w, b}; 
	}
	dp[0][0] = true; 
	for (int i = 0; i < len; i++)
	{
		for (int x = 0; x <= n; x++)
		{
			if (dp[i][x])
			{
				dp[i + 1][x + arr[i].first] = true; 
				dp[i + 1][x + arr[i].second] = true; 
			}
		}
	}
	int ans = 1e9; 
	for (int i = 0; i <= n; i++)
	{
		if (dp[len][i])
			ans = std::min(ans, i * (i - 1) / 2 + (n - i) * (n - i - 1) / 2); 
	}
	printf("%d\n", ans >= 1e9 ? -1 : ans);
	return 0; 
}
