#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>pat[1010];
vector<int>idx[1010];
int cnt[1010][1010];
int frm[1010];
int ans[202020];
void dfs(int node, int p, int dir)
{
	if (node == p)return;
	if (cnt[p][node] >= 2)return;
	if (cnt[p][node] == 1 && frm[node] == dir)return;
	if (cnt[p][node] == 0)frm[node] = dir;
	cnt[p][node]++;
	for (int i = 0; i < pat[node].size(); i++)dfs(pat[node][i], p, dir);
}
int main()
{
	int num, way;
	scanf("%d%d", &num, &way);
	for (int i = 0; i < way; i++)
	{
		int za, zb;
		scanf("%d%d", &za, &zb);
		za--, zb--;
		pat[za].push_back(zb);
		idx[za].push_back(i);
	}
	for (int i = 0; i < num; i++)
	{
		fill(frm, frm + num, -1);
		for (int j = 0; j < pat[i].size(); j++)dfs(pat[i][j], i, pat[i][j]);
	}
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < pat[i].size(); j++)
		{
			bool f = cnt[i][pat[i][j]] >= 2;
			bool g = cnt[pat[i][j]][i] >= 1;
			ans[idx[i][j]] = f != g;
		}
	}
	for (int i = 0; i < way; i++)printf(ans[i] ? "diff\n" : "same\n");
}