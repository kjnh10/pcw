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
struct edge { int v, w; };

#define rep(i, N) for (int i = 0; i < N; i++)
#define pb push_back

ll MOD = 1000000007;
ll _MOD = 1000000009;
ll e10 = 1e10 + 10;
double EPS = 1e-10;

int main() {
	int N; cin >> N;
	vector<vector<int> > G(N);
	rep(i, N - 1) {
		int a, b; scanf("%d%d", &a, &b);
		a--; b--;
		G[a].pb(b);
		G[b].pb(a);
	}
	vector<int> d(N, -1);
	priority_queue<i_i, vector<i_i>, greater<i_i> > pq;
	int K; cin >> K;
	while (K--) {
		int v, p; scanf("%d%d", &v, &p);
		v--;
		d[v] = p;
		pq.push(i_i(p, v));
	}
	while (!pq.empty()) {
		i_i p = pq.top(); pq.pop();
		int u = p.second;
		for (int v: G[u])
			if (d[v] == -1) {
				d[v] = d[u] + 1;
				pq.push(i_i(d[v], v));
			}
	}
	rep(u, N)
		for (int v: G[u])
			if (abs(d[u] - d[v]) != 1) {
			cout << "No" << endl;
			return 0;
		}
	cout << "Yes" << endl;
	rep(u, N) printf("%d\n", d[u]);
}
