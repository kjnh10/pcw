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
#include <random>
using namespace std;

#define rep(i, N) for (int i = 0; i < N; i++)
#define pb push_back

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
int INF = INT_MAX / 2;
double EPS = 1e-10;

struct union_find {
	vector<int> v;
	union_find(int n) : v(n, -1) {}
	int find(int x) { return v[x] < 0 ? x : v[x] = find(v[x]); }
	void unite(int x, int y) {
		x = find(x); y = find(y);
		if (x == y) return;
		if (-v[x] < -v[y]) swap(x, y);
		v[x] += v[y]; v[y] = x;
	}
	bool root(int x) { return v[x] < 0; }
	bool same(int x, int y) { return find(x) == find(y); }
	int size(int x) { return -v[find(x)]; }
};

int main() {
	int N, M1, M2;
	cin >> N >> M1 >> M2;
	union_find uf1(N), uf2(N);
	while (M1--) {
		int u, v; scanf("%d%d", &u, &v);
		u--; v--;
		uf1.unite(u, v);
	}
	while (M2--) {
		int u, v; scanf("%d%d", &u, &v);
		u--; v--;
		uf2.unite(u, v);
	}
	map<i_i, int> mp;
	rep(u, N) {
		int x = uf1.find(u), y = uf2.find(u);
		mp[i_i(x, y)]++;
	}
	rep(u, N) {
		int x = uf1.find(u), y = uf2.find(u);
		printf("%d ", mp[i_i(x, y)]);
	}
	cout << endl;
}
