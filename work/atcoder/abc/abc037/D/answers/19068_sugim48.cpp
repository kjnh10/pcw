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
#include <random>
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

int INF = INT_MAX / 2;
ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;

int dy[] = {0, -1, 0, 1};
int dx[] = {-1, 0, 1, 0};

int main() {
	int H, W; cin >> H >> W;
	vector<vector<int> > a(H, vector<int>(W));
	for (int y = 0; y < H; y++)
		for (int x = 0; x < W; x++)
			scanf("%d", &a[y][x]);
	vector<i_i> v;
	for (int y = 0; y < H; y++)
		for (int x = 0; x < W; x++)
			v.push_back(i_i(a[y][x], y * W + x));
	sort(v.begin(), v.end());
	vector<vector<int> > d(H, vector<int>(W));
	for (i_i p: v) {
		int y = p.second / W, x = p.second % W;
		d[y][x] = 1;
		for (int k = 0; k < 4; k++) {
			int _y = y + dy[k], _x = x + dx[k];
			if (_y >= 0 && _y < H && _x >= 0 && _x < W && a[_y][_x] < a[y][x])
				d[y][x] = (d[y][x] + d[_y][_x]) % MOD;
		}
	}
	int ans = 0;
	for (int y = 0; y < H; y++)
		for (int x = 0; x < W; x++)
			ans = (ans + d[y][x]) % MOD;
	cout << ans << endl;
}
