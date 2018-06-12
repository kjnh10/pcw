#include <bits/stdc++.h>
using namespace std;

int chA[200005], chB[200005];
vector<int> ch[1005];
bool two[1005][1005];
bool care[1005];
int sccid[1005];
bool ons[1005];
int vis[1005];
int idx[1005];
vector<int> S;
int lo[1005];
int n, m;

void dfs1(int at, int fr, int via)
{
	if (care[at] && via != at) two[fr][at] = true;
	if (vis[at] == -1) vis[at] = via;
	else if (vis[at] == -2) return;
	else if (vis[at] == via) return;
	else vis[at] = -2;
	for (int u: ch[at]) dfs1(u, fr, via);
}

int dfs2(int at)
{
	static int Y, Z;
	idx[at] = lo[at] = ++Z;
	S.push_back(at); ons[at] = true;
	for (int u: ch[at])
		if (!idx[u]) lo[at] = min(lo[at], dfs2(u));
		else if (ons[u]) lo[at] = min(lo[at], idx[u]);
	if (idx[at] == lo[at])
	{
		Y++;
		while (true)
		{
			int u = S.back(); S.pop_back();
			ons[u] = false;
			sccid[u] = Y;
			if (u == at) break;
		}
	}
	return lo[at];
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0;i < m;i++)
	{
		scanf("%d%d", chA+i, chB+i);
		ch[--chA[i]].push_back(--chB[i]);
	}
	for (int i = 0;i < n;i++)
	{
		for (int u: ch[i]) care[u] = true;
		for (int j = 0;j < n;j++) vis[j] = -1;
		vis[i] = -2;
		for (int u: ch[i]) dfs1(u, i, u);
		for (int u: ch[i]) care[u] = false;
	}
	for (int i = 0;i < n;i++) if (!idx[i]) dfs2(i);
	for (int i = 0;i < m;i++) printf("%s\n", ((sccid[chA[i]] == sccid[chB[i]]) == (two[chA[i]][chB[i]]))?"same":"diff");
	return 0;
}
