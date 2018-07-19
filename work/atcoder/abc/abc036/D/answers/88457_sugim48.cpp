#define _USE_MATH_DEFINES
#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <time.h>
#include <vector>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef pair<double, int> d_i;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> d_d;
struct edge { int u, v; ll w; };

ll MOD = 1000000007; 
ll _MOD = 1000000009;
double EPS = 1e-10;

i_i dfs(int u, int p, vector<vector<int> >& G) {
	ll x = 1, y = 1;
	for (int v: G[u]) {
		if (v == p) continue;
		i_i xy = dfs(v, u, G);
		x = x * (xy.first + xy.second) % MOD;
		y = y * xy.first % MOD;
	}
	return i_i(x, y);
}

int main() {
	int N; cin >> N;
	vector<vector<int> > G(N);
	for (int i = 0; i < N - 1; i++) {
		int x, y; scanf("%d%d", &x, &y);
		x--; y--;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	i_i xy = dfs(0, -1, G);
	cout << (xy.first + xy.second) % MOD << endl;
}
