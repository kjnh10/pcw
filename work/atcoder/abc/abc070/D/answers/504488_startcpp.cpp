#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#define int long long
using namespace std;

int n;
vector<int> et[100000];
vector<int> ec[100000];
int q, r;
int x, y;
int dist[100000];

void dfs(int v, int p = -1, int d = 0) {
	dist[v] = d;
	for (int i = 0; i < et[v].size(); i++) {
		if (et[v][i] == p) continue;
		dfs(et[v][i], v, d + ec[v][i]);
	}
}

signed main() {
	int i;
	
	cin >> n;
	for (i = 0; i < n - 1; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		a--; b--;
		et[a].push_back(b);
		et[b].push_back(a);
		ec[a].push_back(c);
		ec[b].push_back(c);
	}
	
	cin >> q >> r;
	r--;
	
	dfs(r);
	
	for (i = 0; i < q; i++) {
		cin >> x >> y;
		x--; y--;
		cout << dist[x] + dist[y] << endl;
	}
	return 0;
}