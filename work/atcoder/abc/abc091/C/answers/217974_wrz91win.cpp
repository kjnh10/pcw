#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxn = 1100;

vector<int> g[maxn];
bool vis[maxn];
int match[maxn];

bool magyar(int u)
{
	for (int i = 0;i < g[u].size();++i)
	{
		int v = g[u][i];
		if (!vis[v])
		{
			vis[v] = true;
			if (!match[v] || magyar(match[v]))
			{
				match[u] = v;
				match[v] = u;
				return true;
			}
		}
	}
	return false;
}

int px[maxn], py[maxn];
int px2[maxn], py2[maxn];

int main(int argc, char * argv[])
{
	int n;
	scanf("%d", &n);
	for (int i = 1;i <= n;++i)
	{
		scanf("%d%d", &px[i], &py[i]);
	}
	for (int i = 1;i <= n;++i)
	{
		scanf("%d%d", &px2[i], &py2[i]);
	}
	for (int i = 1;i <= n;++i)
	{
		for (int j = 1;j <= n;++j)
		{
			if (px[i] < px2[j] && py[i] < py2[j])
			{
				g[i].push_back(n + j);
				g[n + j].push_back(i);
			}
		}
	}
	int ans = 0;
	for (int i = 1;i <= n;++i)
	{
		memset(vis, false, sizeof vis);
		if (magyar(i)) ans++;
	}
	printf("%d\n", ans);
	return 0;
}

