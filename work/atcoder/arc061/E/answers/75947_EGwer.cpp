#include<stdio.h>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
typedef pair<int, int>pii;
typedef pair<pii, int>pi3;
vector<pii>pat[600000];
bool flag[600000];
int dist[600000];
int main()
{
	int num, way;
	scanf("%d%d", &num, &way);
	vector<pii>zat;
	vector<pi3>zp;
	for (int i = 0; i < way; i++)
	{
		int za, zb, zc;
		scanf("%d%d%d", &za, &zb, &zc);
		za--, zb--, zc--;
		zat.push_back(make_pair(za, zc));
		zat.push_back(make_pair(zb, zc));
		zp.push_back(make_pair(make_pair(za, zb), zc));
		zp.push_back(make_pair(make_pair(zb, za), zc));
	}
	sort(zat.begin(), zat.end());
	for (int i = 0; i < zat.size(); i++)
	{
		pat[num + i].push_back(make_pair(zat[i].first, 0));
		pat[zat[i].first].push_back(make_pair(num + i, 1));
	}
	for (int i = 0; i < zp.size(); i++)
	{
		int l1 = lower_bound(zat.begin(), zat.end(), make_pair(zp[i].first.first, zp[i].second)) - zat.begin();
		int l2 = lower_bound(zat.begin(), zat.end(), make_pair(zp[i].first.second, zp[i].second)) - zat.begin();
		pat[l1 + num].push_back(make_pair(l2 + num, 0));
	}
	priority_queue<pii>que;
	que.push(make_pair(0, 0));
	fill(dist, dist + 600000, 1000000000);
	for (;;)
	{
		if (que.empty())break;
		pii z = que.top();
		que.pop();
		if (flag[z.second])continue;
		flag[z.second] = true;
		for (int i = 0; i < pat[z.second].size(); i++)
		{
			if (dist[pat[z.second][i].first]>-z.first + pat[z.second][i].second)
			{
				dist[pat[z.second][i].first] = -z.first + pat[z.second][i].second;
				que.push(make_pair(-dist[pat[z.second][i].first], pat[z.second][i].first));
			}
		}
	}
	if (flag[num - 1])printf("%d\n", dist[num - 1]);
	else printf("-1\n");
}