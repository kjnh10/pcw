#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define MOD @
#define ADD(X,Y) ((X) = ((X) + (Y)%MOD) % MOD)
typedef long long i64; typedef vector<int> ivec; typedef vector<string> svec;

int N;
bool C[101010];
char in[101010];
set<int> tree[101010];
bool valid[101010];
int profit[101010];

void rm_edge(int x, int y)
{
	tree[x].erase(y);
	tree[y].erase(x);
}

void visit(int p)
{
	if (C[p]) return;
	if (tree[p].size() == 1) {
		valid[p] = false;
		int q = *(tree[p].begin());
		rm_edge(p, q);
		visit(q);
	}
}

vector<int> graph[101010];
int best = 0;

void update_best(pair<pair<int,int>, pair<int,int>>& p, pair<int, int> v)
{
	if (v > p.first) {
		p.second = p.first;
		p.first = v;
	} else if (v > p.second) {
		p.second = v;
	}
}

pair<int, int> solve(int p, int rt)
{
	// non leaf, any
	pair<pair<int, int>, pair<int, int> > nl{ {0, -1}, {0, -1} }, any{ {0, -1}, {0, -1} };
	for (int i = 0; i < graph[p].size(); ++i) {
		int q = graph[p][i];
		if (q == rt) continue;

		auto tmp = solve(q, p);
		update_best(nl, { tmp.first, i });
		update_best(any, { tmp.second, i });
	}
	best = max(best, profit[p] + nl.first.first + nl.second.first);
	if (nl.first.second != any.first.second) best = max(best, profit[p] + nl.first.first + any.first.first);
	else {
		best = max(best, profit[p] + nl.first.first + any.second.first);
		best = max(best, profit[p] + nl.second.first + any.first.first);
	}

	if (graph[p].size() == 1) {
		return { -10, profit[p] };
	}
	return { nl.first.first + profit[p], any.first.first + profit[p] };
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N - 1; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		--x; --y;
		tree[x].insert(y);
		tree[y].insert(x);
	}
	scanf("%s", in);
	for (int i = 0; i < N; ++i) C[i] = in[i] == 'W';

	bool hasW = false;
	for (int i = 0; i < N; ++i) if (C[i]) hasW = true;

	if (!hasW) {
		puts("0");
		return 0;
	}

	fill(valid, valid + N, true);
	for (int i = 0; i < N; ++i) visit(i);

	int base = -2;
	int ep = -1;
	int cnt = 0;
	for (int i = 0; i < N; ++i) if (valid[i]) {
		++cnt;
		base += 2;
		ep = i;
		if ((tree[i].size() % 2 != 0) != C[i]) ++base;
		for (int j : tree[i]) graph[i].push_back(j);
	}

	if (cnt == 1) {
		puts("1");
		return 0;
	}

	for (int i = 0; i < N; ++i) if (valid[i]) {
		profit[i] = ((tree[i].size() % 2 != 0) != C[i]) ? 2 : 0;
	//	printf("%d %d\n", i, profit[i]);
	}

	//printf("%d\n", base);

	solve(ep, -1);
	
	printf("%d\n", base + min(-best, 0));
	return 0;
}
