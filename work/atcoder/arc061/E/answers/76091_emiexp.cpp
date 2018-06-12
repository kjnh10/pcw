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

int N, M;
map<pair<int, int>, int> stnid;
int idlast;
vector<pair<int, int> > graph[606060];
bool vis[606060];

void ae(int p, int q, int c, int d)
{
	graph[p].push_back({ q, c });
	graph[q].push_back({ p, d });
}

int getid(int stn, int cmp)
{
	if (stnid.count({ stn, cmp })) return stnid[{stn, cmp}];
	int ret = idlast++;
	ae(stn, ret, 1, 0);
	return stnid[{stn, cmp}] = ret;
}

int main()
{
	scanf("%d%d", &N, &M);
	idlast = N;
	for (int i = 0; i < M; ++i) {
		int p, q, c;
		scanf("%d%d%d", &p, &q, &c);
		--p; --q;

		int a = getid(p, c);
		int b = getid(q, c);
		ae(a, b, 0, 0);
	}

	priority_queue<pair<int, int> > Q;
	for (int i = 0; i < idlast; ++i) vis[i] = false;
	Q.push({ 0, 0 });
	while (!Q.empty()) {
		pair<int, int> tmp = Q.top(); Q.pop();
		int cost = -tmp.first;
		int pt = tmp.second;
		if (vis[pt]) continue;
		vis[pt] = true;
		if (pt == N - 1) {
			printf("%d\n", cost);
			return 0;
		}
		for (auto e : graph[pt]) {
			Q.push({ -(cost + e.second), e.first });
		}
	}
	puts("-1");
	return 0;
}
