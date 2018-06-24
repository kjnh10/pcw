#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int d[100][100];
typedef pair<int, int>pii;
typedef pair<pii, int>pi3;
int x[1000];
int main()
{
	int num, way;
	scanf("%d%d", &num, &way);
	for (int i = 0; i < num; i++)for (int j = 0; j < num; j++)d[i][j] = 1000000000;
	for (int i = 0; i < num; i++)d[i][i] = 0;
	vector<pi3>v;
	for (int i = 0; i < way; i++)
	{
		int za, zb, zc;
		scanf("%d%d%d", &za, &zb, &zc);
		za--, zb--;
		d[za][zb] = d[zb][za] = zc;
		v.push_back(make_pair(make_pair(za, zb), zc));
	}
	for (int i = 0; i < num; i++)for (int j = 0; j < num; j++)for (int k = 0; k < num; k++)d[j][k] = min(d[j][k], d[j][i] + d[i][k]);
	int r = 0;
	for (int i = 0; i < way; i++)
	{
		int s = v[i].first.first, t = v[i].first.second;
		int q = v[i].second;
		bool f = false;
		for (int j = 0; j < num; j++)if (d[j][s] + q == d[j][t] || d[j][t] + q == d[j][s])f = true;
		if (!f)r++;
	}
	printf("%d\n", r);
}