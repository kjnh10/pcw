#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
#define SIZE 262144
class segtree1
{
public:
	int seg[SIZE * 2];
	void init()
	{
		fill(seg, seg + SIZE * 2, 1000000000);
	}
	void update(int a, int b)
	{
		a += SIZE;
		seg[a] = min(seg[a], b);
		for (;;)
		{
			a /= 2;
			if (a == 0)break;
			seg[a] = min(seg[a * 2], seg[a * 2 + 1]);
		}
	}
	int get(int beg, int end, int node, int lb, int ub)
	{
		if (ub < beg || end < lb)return 1000000000;
		if (beg <= lb&&ub <= end)return seg[node];
		return min(get(beg, end, node * 2, lb, (lb + ub) / 2), get(beg, end, node * 2 + 1, (lb + ub) / 2 + 1, ub));
	}
};
segtree1 tree1;
class segtree2
{
public:
	int seg[SIZE * 2];
	void init()
	{
		fill(seg, seg + SIZE * 2, 1000000000);
	}
	void update(int beg, int end, int node, int lb, int ub, int num)
	{
		if (ub < beg || end < lb)return;
		if (beg <= lb&&ub <= end)
		{
			seg[node] = min(seg[node], num);
			return;
		}
		update(beg, end, node * 2, lb, (lb + ub) / 2, num);
		update(beg, end, node * 2 + 1, (lb + ub) / 2 + 1, ub, num);
	}
	int get(int pl, int node, int lb, int ub)
	{
		if (lb == ub)return seg[node];
		if (pl <= (lb + ub) / 2)return min(seg[node], get(pl, node * 2, lb, (lb + ub) / 2));
		else return min(seg[node], get(pl, node * 2 + 1, (lb + ub) / 2 + 1, ub));
	}
};
segtree2 tree2;
int d[300000], r[300000];
typedef pair<int, int>pii;
int main()
{
	int num, query;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)scanf("%d", &d[i]);
	for (int i = num - 1; i >= 0; i--)r[i] = r[i + 1] + d[i];
	scanf("%d", &query);
	vector<pii>v;
	for (int i = 0; i < query; i++)
	{
		int za, zb;
		scanf("%d%d", &za, &zb);
		za--, zb--;
		v.push_back(make_pair(zb, za));
	}
	sort(v.begin(), v.end());
	tree1.init();
	tree2.init();
	tree1.update(0, r[0]);
	int mini = r[0];
	for (int i = 0; i < v.size(); i++)
	{
		int s = v[i].second, t = v[i].first;
		int a = tree1.get(0, s, 1, 0, SIZE - 1) - (r[s] - r[t + 1]) + (t - s + 1 - (r[s] - r[t + 1]));
		int b = tree2.get(s, 1, 0, SIZE - 1) + r[t + 1] - (num - 1 - t - r[t + 1]);
		int x = min(a, b);
		//printf("%d %d  %d\n", s, t, x);
		mini = min(mini, x);
		tree1.update(t + 1, x);
		tree2.update(s, t, 1, 0, SIZE - 1, x - r[t + 1] + (num - 1 - t - r[t + 1]));
	}
	printf("%d\n", mini);
}