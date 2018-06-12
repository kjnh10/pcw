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
#include <cmath>
#include <map>
using namespace std;
#define MOD 1000000007
#define ADD(X,Y) ((X) = ((X) + (Y)%MOD) % MOD)
typedef long long i64; typedef vector<int> ivec; typedef vector<string> svec;

int N, M, S;
vector<int> graph[202020];
int mxp[202020];

int main()
{
	scanf("%d%d%d", &N, &M, &S);
	--S;
	for (int i = 0; i < M; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		--u; --v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	for (int i = 0; i < N; ++i) mxp[i] = -1;

	priority_queue<pair<int, int> > Q;
	Q.push(make_pair(S, S));

	while (!Q.empty()) {
		int p = Q.top().second;
		int v = Q.top().first;
		Q.pop();
		if (mxp[p] != -1) continue;
		mxp[p] = v;

		for (int q : graph[p]) {
			Q.push(make_pair(min(v, q), q));
		}
	}
	for (int i = 0; i < N; ++i) if (mxp[i] == i) printf("%d\n", i + 1);

	return 0;
}
