#include <bits/stdc++.h>

typedef long long ll;
typedef long long llong;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;

const ll MOD = 1e9 + 7;
ll pw(ll a, ll b) {
	ll ans = 1; while (b) {
		while (!(b & 1)) b >>= 1, a = (a * a) % MOD;
		ans = (ans * a) % MOD, --b;
	} return ans;
}
const int MAXN = 210000;

ll fc[MAXN];
ll bfc[MAXN]; 
int was[MAXN];
vector<int> fr;
vector<int> st;
vector<int> vv;
vector<int> eds[MAXN];
int sz[MAXN];
int en[MAXN];

ll cnk(int n, int k) {
	if (k > n)
		return 0;
	return fc[n] * bfc[k] % MOD * bfc[n - k] % MOD;
}

int dfs1(int v, int p) {
	was[v] = 1;
	st.push_back(v);
	for (int u: eds[v]) {
		if (u == p)
			continue;
		if (was[u]) {
			for (int j = 0; j < st.size(); ++j) {
				if (st[j] == u) {
					for (int k = j; k < st.size(); ++k)
						vv.push_back(st[k]);
					break;
				}
			}
			return 1;
		}
		if (dfs1(u, v))
			return 1;
	}
	st.pop_back();
	return 0;
}

pair<int, ll> dfs2(int v, int p, int tm) {
	was[v] = tm;
	int sz = 0;
	ll cur = 1;
	for (int u: eds[v]) {
		if (was[u] >= tm)
			continue;
		pair<int, ll> tmp = dfs2(u, v, tm);
		cur = (cur * tmp.second) % MOD;
		if (u > p) {
			fr.push_back(tmp.first);
		}
		else {
			cur = cur * cnk(sz + tmp.first, tmp.first) % MOD;
			sz += tmp.first;
		}
	}
	return make_pair(sz + 1, cur);
}

pair<ll, int> func(int k, int tm) {
	ll cur = 1;
	fr.clear();
	for (int i = 1; i <= k; ++i) {
		int go = vv[i + 1];
		int ng = vv[i - 1];
		pair<int, ll> tmp = dfs2(vv[i], go, tm);
		sz[i] = tmp.first;
		cur = (cur * tmp.second) % MOD;
		if (go < ng)
			en[i] = 1;
		else
			en[i] = 0;
	}
	int csz = 0;
	for (int i = 1; i <= k; ++i) {
		if (en[i]) {
			if (csz)
				fr.push_back(csz);
			csz = sz[i];
		}
		else if (!csz) {
			continue;
		}
		else {
			cur = cur * cnk(csz + sz[i] - 1, sz[i] - 1) % MOD; 
			csz += sz[i];
		}
	}
	if (!csz)
		cur = 0;
	for (int i = 1; i <= k; ++i) {
		if (en[i]) {
			if (csz)
				fr.push_back(csz);
			break;
		}
		else {
			cur = cur * cnk(csz + sz[i] - 1, sz[i] - 1) % MOD; 
			csz += sz[i];
		}
	}
	csz = 0;
	for (int i: fr) {
		csz += i;
		cur = (cur * cnk(csz, i)) % MOD;
	}
	return make_pair(cur, csz);
}

int n;

int main() {
	fc[0] = bfc[0] = 1;
	for (int i = 1; i < MAXN; ++i)
		fc[i] = (fc[i - 1] * i) % MOD, bfc[i] = pw(fc[i], MOD - 2);
	scanf("%d", &n);
	for (int i = 0; i < n * 2; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		--x, --y;
		eds[x].push_back(y + n);
		eds[y + n].push_back(x);
	}
	ll ans = 1;
	int csz = 0;
	for (int i = 0; i < 2 * n; ++i) {
		if (was[i])
			continue;
		vv.clear();
		st.clear();
		if (!dfs1(i, -1)) {
			cout << 0 << "\n";
			return 0;
		}
		int k = vv.size();
		vv.push_back(vv[0]);
		vv.push_back(vv[1]);
		ll sum = 0;
		int sz = 0;
		for (int u: vv)
			was[u] = 2;
		tie(sum, sz) = func(k, 2);
		reverse(vv.begin(), vv.end());
		for (int u: vv)
			was[u] = 3;
		sum = (sum + func(k, 3).first) % MOD;
		ans = (ans * sum) % MOD;
		csz += sz;
		ans = (ans * cnk(csz, sz)) % MOD;
	}
	cout << ans << "\n";
	return 0;
}


