#ifndef LOCAL
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

typedef long long ll;
typedef long long llong;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;

/*
ll pw(ll a, ll b) {
	ll ans = 1; while (b) {
		while (!(b & 1)) b >>= 1, a = (a * a) % MOD;
		ans = (ans * a) % MOD, --b;
	} return ans;
}
*/
const ll INF = 1e18;
const ll MOD = 1e9 + 7;

set<pair<ll, int> > ss;
int n;
const int MAXN = 210000;

int m;
int s, t;

vector<pair<int, ll> > eds[MAXN];

void solve(int s, pair<ll, ll> *dd) {
	for (int i = 0; i < n; ++i)
		dd[i] = make_pair(INF, 0);
	dd[s] = make_pair(0, 1);
	ss.clear();
	ss.insert(make_pair(dd[s].first, s));
	while (!ss.empty()) {
		int x = ss.begin()->second;
		ss.erase(ss.begin());
		for (auto e: eds[x]) {
			int u = e.first;
			if (dd[u].first > dd[x].first + e.second) {
				ss.erase(make_pair(dd[u].first, u));
				dd[u].first = dd[x].first + e.second;
				ss.insert(make_pair(dd[u].first, u));
				dd[u].second = 0;
			}
			if (dd[u].first == dd[x].first + e.second)
				dd[u].second = (dd[u].second + dd[x].second) % MOD;
		}
	}
}


pair<ll, ll> ds[MAXN];
pair<ll, ll> dt[MAXN];

vector<tuple<int, int, ll> > ed;


int main() {
	scanf("%d%d", &n, &m);
	scanf("%d%d", &s, &t);
	--s, --t;
	for (int i = 0; i < m; ++i) {
		int a, b;
		ll c;
		scanf("%d%d%lld", &a, &b, &c);
		--a, --b;
		eds[a].push_back(make_pair(b, c));
		eds[b].push_back(make_pair(a, c));
		ed.push_back(make_tuple(a, b, c));
		ed.push_back(make_tuple(b, a, c));
	}
	solve(s, ds);
	solve(t, dt);
	ll ans = ds[t].second * ds[t].second % MOD;
	for (int i = 0; i < n; ++i) {
		if (ds[i].first == dt[i].first && ds[i].first * 2 == ds[t].first) {
			ll go = ds[i].second * dt[i].second % MOD;
			ans = (ans - go * go % MOD + MOD) % MOD;
		}
	}
	for (int i = 0; i < ed.size(); ++i) {
		int a, b;
		ll c;
		tie(a, b, c) = ed[i];
		if (c + ds[a].first + dt[b].first == ds[t].first) {
			if (ds[a].first * 2 < ds[t].first && dt[b].first * 2 < ds[t].first) {
				ll go = ds[a].second * dt[b].second % MOD;
				ans = (ans - go * go % MOD + MOD) % MOD;
			}
		}
	}
	cout << ans << "\n";
	return 0;
}


