#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

#define free gkjnfde

const ll MOD = (ll)1e9 + 7;
ll add(ll x, ll y) {
	x += y;
	if (x >= MOD) return x - MOD;
	return x;
}
ll sub(ll x, ll y) {
	x -= y;
	if (x < 0) return x + MOD;
	return x;
}
ll mult(ll x, ll y) {
	return (x * y) % MOD;
}
ll bin_pow(ll x, ll p) {
	if (p == 0) return 1;
	if (p & 1) return mult(x, bin_pow(x, p - 1));
	return bin_pow(mult(x, x), p / 2);
}
ll rev(ll x) {
	return bin_pow(x, MOD - 2);
}

const int N = 200200;
ll f[N], rf[N];

ll getC(int n, int k) {
	if (k < 0 || k > n) return 0;
	return mult(f[n], mult(rf[k], rf[n - k]));
}

int n;
vector<int> g[2][N];
vector<int> G[N];
int id[2][N];
int ver[N][2];
int curDeg[N];
int q[N];
int myPoint[N][2];
int topQ;
int sz;
int cycle[N];
int cycSz;
bool free[N];
vector<int> T[N];
int S[N];
int ALL = 0;

void dfs1(int t, int v) {
	id[t][v] = sz;
	ver[sz][0] = t;
	ver[sz][1] = v;
	sz++;
	for (int u : g[t][v]) {
		if (id[t ^ 1][u] != -1) continue;
		dfs1(t ^ 1, u);
	}
}

void findCycle(int v) {
	cycle[cycSz++] = v;
	curDeg[v] = 0;
	for (int u : G[v]) {
		if (curDeg[u] <= 1) continue;
		findCycle(u);
	}
}

ll dfs2(int v) {
	S[v] = 0;
	ll ans = 1;
	for (int u : T[v]) {
		ans = mult(ans, dfs2(u));
		S[v] += S[u];
		ans = mult(ans, getC(S[v], S[u]));
	}
	S[v]++;
	return ans;
}

ll solve2() {
//	printf("SOLVE2\n");
	for (int i = 0; i < sz; i++) {
		free[i] = true;
		T[i].clear();
	}
	for (int i = 0; i < sz; i++) {
		int t = ver[i][0];
		int x = ver[i][1];
		int y = myPoint[i][t ^ 1];
		int v = id[t ^ 1][y];
		if (myPoint[v][t] > x) {
//			printf("%d %d\n", v, i);
			T[v].push_back(i);
			free[i] = false;
		}
	}
	int all = 0;
	ll ans = 1;
	for (int i = 0; i < sz; i++) {
		if (!free[i]) continue;
		ans = mult(ans, dfs2(i));
		all += S[i];
		ans = mult(ans, getC(all, S[i]));
	}
	return ans;
}

ll solve(int x) {
	sz = 0;
	dfs1(0, x);
	int sumDeg = 0;
	for (int i = 0; i < sz; i++) {
		int t = ver[i][0], v = ver[i][1];
		curDeg[i] = (int)g[t][v].size();
		sumDeg += curDeg[i];
		G[i].clear();
		for (int u : g[t][v])
			G[i].push_back(id[t ^ 1][u]);
	}
	if (sumDeg != sz * 2) return 0;
	topQ = 0;
	for (int i = 0; i < sz; i++) {
		if (curDeg[i] <= 1) {
			q[topQ++] = i;
		}
	}
	for (int i = 0; i < topQ; i++) {
		int v = q[i];
		for (int u : G[v]) {
			if (curDeg[u] <= 1) continue;
			myPoint[v][ver[v][0]] = ver[v][1];
			myPoint[v][ver[v][0] ^ 1] = ver[u][1];
			curDeg[u]--;
			if (curDeg[u] <= 1)
				q[topQ++] = u;
		}
	}
	cycSz = 0;
	for (int i = 0; i < sz; i++) {
		if (curDeg[i] <= 1) continue;
		findCycle(i);
		break;
	}
/*
	for (int i = 0; i < sz; i++)
		printf("%d %d\n", ver[i][0], ver[i][1]);
	for (int i = 0; i < cycSz; i++)
		printf("%d ", cycle[i]);
	printf("\n\n");
*/
	ll ans = 0;

	for (int i = 0; i < cycSz; i++) {
		int v = cycle[i], u = cycle[(i + 1) % cycSz];
		myPoint[v][ver[v][0]] = ver[v][1];
		myPoint[v][ver[v][0] ^ 1] = ver[u][1];
	}
	/*
	for (int i = 0; i < sz; i++)
		printf("%d %d\n", myPoint[i][0], myPoint[i][1]);
	*/
	ans = add(ans, solve2());

	for (int i = 0; i < cycSz; i++) {
		int v = cycle[i], u = cycle[(i - 1 + cycSz) % cycSz];
		myPoint[v][ver[v][0]] = ver[v][1];
		myPoint[v][ver[v][0] ^ 1] = ver[u][1];
	}
	ans = add(ans, solve2());

	ALL += sz;

	return ans;
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	f[0] = 1;
	for (int i = 1; i < N; i++)
		f[i] = mult(f[i - 1], i);
	rf[N - 1] = rev(f[N - 1]);
	for (int i = N - 1; i > 0; i--)
		rf[i - 1] = mult(rf[i], i);
/*
	printf("%lld\n", getC(5, 3));
	return 0;
*/
	ll ans = 1;

	scanf("%d", &n);
	for (int i = 0; i < 2 * n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		x--;y--;
		g[0][x].push_back(y);
		g[1][y].push_back(x);
	}
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < n; j++)
			id[i][j] = -1;
	for (int i = 0; i < n; i++) {
		if (id[0][i] != -1) continue;
		if (g[0][i].empty()) {
			printf("0\n");
			return 0;
		}
		int old = ALL;
		ans = mult(ans, solve(i));
		ans = mult(ans, getC(ALL, old));
	}
	printf("%lld\n", ans);

	return 0;
}
