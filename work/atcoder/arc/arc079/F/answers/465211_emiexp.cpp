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

int N, P[202020];
vector<int> graph[202020];
int rev[202020];
bool oncyc[202020];
int grundy[202020];

int cgrundy(vector<int> &vec)
{
	sort(vec.begin(), vec.end());

	if (vec.size() == 0) return 0;
	if (vec[0] != 0) return 0;

	for (int i = 0; i < vec.size() - 1; ++i) {
		if (vec[i] + 1 < vec[i + 1]) return vec[i] + 1;
	}
	return vec.back() + 1;
}

int decide(int p)
{
	if (grundy[p] != -1) return grundy[p];
	vector<int> ch;
	for (int q : graph[p]) {
		ch.push_back(decide(q));
	}
	return grundy[p] = cgrundy(ch);
}

bool solve(int p, int v)
{
	for (int i = 0; i < N; ++i) grundy[i] = -1;
	grundy[p] = v;

	for (int i = 0; i < N; ++i) decide(i);

	vector<int> ch;
	for (int q : graph[p]) {
		ch.push_back(decide(q));
	}

	//printf("%d %d\n", v, cgrundy(ch));
	return v == cgrundy(ch);
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		scanf("%d", P + i);
		--P[i];
		graph[P[i]].push_back(i);
		oncyc[i] = false;
	}

	int r = 0;
	for (int i = 0; i < 2 * N; ++i) r = P[r];

	vector<int> cyc;
	int r2 = r;
	do {
		cyc.push_back(r2);
		r2 = P[r2];
	} while (r2 != r);

	for (int p : cyc) oncyc[p] = true;

	for (int i = 0; i < N; ++i) grundy[i] = -1;
	vector<int> ori;
	for (int q : graph[r]) {
		if (!oncyc[q]) {
			ori.push_back(decide(q));
		}
	}

	int low = cgrundy(ori);
	//printf("%d %d\n", r, low);
	bool ret = false;
	ret |= solve(r, low);
	//printf("%d\n", low);
	ori.push_back(low);
	low = cgrundy(ori);
	//printf("%d\n", low);

	ret |= solve(r, low);
	puts(ret ? "POSSIBLE" : "IMPOSSIBLE");

	return 0;
}
