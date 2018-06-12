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

int t;
vector<int> unko;

int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}

bool dfs(int u, int p, vector<vector<int> >& G, vector<int>& path, vector<bool>& vis, bool flag) {
	if (vis[u]) return false;
	vis[u] = true;
	path.push_back(u);
	if (u == t) {
		unko = path;
		return true;
	}
	if (flag) reverse(G[u].begin(), G[u].end());
	for (int v: G[u]) {
		if (v == p) continue;
		if (dfs(v, u, G, path, vis, flag)) {
			if (flag) reverse(G[u].begin(), G[u].end());
			return true;
		}
	}
	path.pop_back();
	if (flag) reverse(G[u].begin(), G[u].end());
	return false;
}

ll extgcd(ll a, ll b, ll& x, ll& y) {
	if (b == 0) {
		x = (a >= 0) ? 1 : -1;
		y = 0;
		return abs(a);
	}
	else {
		ll res = extgcd(b, a % b, y, x);
		y -= (a / b) * x;
		return res;
	}
}

ll mod_inverse(ll a, ll m) {
	ll x, y;
	extgcd(a, m, x, y);
	return (m + x % m) % m;
}

ll c(ll n, ll k) {
	ll res = 1;
	for (int i = 0; i < k; i++)
		res = (res * ((n - i) % 1000000007)) % 1000000007;
	for (int i = 1; i <= k; i++)
		res = (res * mod_inverse(i, 1000000007)) % 1000000007;
	return res;
}

struct union_find {
	vector<int> v;
	union_find(int n) : v(n, -1) {}
	int find(int x) { return (v[x] < 0) ? x : (v[x] = find(v[x])); }
	void unite(int x, int y) {
		x = find(x); y = find(y);
		if (x != y) {
			if (-v[x] < -v[y]) swap(x, y);
			v[x] += v[y]; v[y] = x;
		}
	}
	bool same(int x, int y) { return find(x) == find(y); }
	int size(int x) { return -v[find(x)]; }
};

int main() {
	int N, M, K;
	cin >> N >> M >> K;
	vector<int> a(M), b(M);
	for (int i = 0; i < M; i++) {
		cin >> a[i] >> b[i];
		a[i]--; b[i]--;
	}
	vector<vector<int> > G(N);
	for (int i = 0; i < M; i++) {
		G[a[i]].push_back(b[i]);
		G[b[i]].push_back(a[i]);
	}
	ll ans = 1;
	union_find uf(N);
	union_find uf2(N);
	set<set<int> > hoge;
	for (int i = 0; i < M; i++) {
		vector<int> a1, a2;
		t = b[i];
		{
			unko.clear();
			vector<int> path;
			vector<bool> vis(N);
			dfs(a[i], b[i], G, path, vis, false);
			a1 = unko;
		}
		{
			unko.clear();
			vector<int> path;
			vector<bool> vis(N);
			dfs(a[i], b[i], G, path, vis, true);
			a2 = unko;
		}
		if (a1.empty()) {
			ans = ans * K % MOD;
		}
		else if (a1 == a2) {
			set<int> poyo;
			for (int u: a1) poyo.insert(u);
			hoge.insert(poyo);
		}
		else {
			uf.unite(a[i], b[i]);
			uf.unite(a[i], a1[1]);
			uf.unite(a[i], a2[1]);
		}
	}
	for (int u = 0; u < N; u++)
		if (uf.find(u)==u && uf.size(u) > 1) {
			int n = 0;
			for (int i = 0; i < M; i++)
				if (uf.find(a[i]) == u && uf.find(b[i]) == u)
					n++;
			ans = ans * c(n + K - 1, K - 1) % MOD;
		}
	for (set<int> poyo: hoge)
		if (true) {
			int n = poyo.size();
			ll sum = 0;
			for (int d = 0; d < n; d++) {
				int k = gcd(n, d);
				ll x = 1;
				while (k--) x = x * K % MOD;
				sum = (sum + x) % MOD;
			}
			ans = ans * sum % MOD * mod_inverse(n, MOD) % MOD;
		}
	cout << ans << endl;
}
