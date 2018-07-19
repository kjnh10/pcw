#include <bits/stdc++.h>
#include <random>
using namespace std;

#define rep(i, N) for (int i = 0; i < N; i++)
#define pb push_back

typedef long long ll;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef pair<ll, ll> ll_ll;
struct edge { int v, w; };
const int INF = INT_MAX / 2;
const int MOD = 1e9 + 7;
const ll e18 = 1e18;

ll pow_mod(ll x, ll n, int M) {
	ll ans = 1;
	for (; n; n>>=1) {
		if (n & 1) ans = ans * x % M;
		x = x * x % M;
	}
	return ans;
}

int f(ll x) {
	return x ? 1 + f(x / 10) : 0;
}

int main() {
	ll S; cin >> S;
	ll ans = 0;
	ll r = 1, s = 0;
	for (ll l = 1; l < 10000000; s -= f(l++)) {
		for (; s < S; s += f(r++));
		if (s == S) ans++;
	}
	for (ll k = 8; k * 2 <= S; k++) {
		ll lb = S % k;
		if (!lb) lb = k;
		if (lb > (S - k) / (k + 1)) continue;
		ans += ((S - k) / (k + 1) - lb) / k + 1;
		if (ans >= MOD) ans -= MOD;
	}
	ans %= MOD;
	vector<ll> ks;
	for (ll k = 1; k * k <= S; k++) if (S % k == 0) {
		ks.pb(k);
		if (S / k != k) ks.pb(S / k);
	}
	for (ll k: ks) if (k >= 8)
		ans = (ans + pow_mod(10, k - 1, MOD) * 9 - S / k + 1) % MOD;
	cout << ans << endl;
}
