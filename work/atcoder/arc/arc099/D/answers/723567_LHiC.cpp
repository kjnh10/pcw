#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

#define FASTIO

#ifdef FASTIO
#define scanf abacaba
#define printf abacaba
#endif

typedef long long ll;
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

ll get(ll x) {
	ll ans = 0;
	while (x) {
		ans += x % 10;
		x /= 10;
	}
	return ans;
}

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	set<ll> ss;
	ll now = 1;
	for (int i = 0; i <= 15; ++i, now *= 10) {
		for (ll j = 0;; ++j) {
			ll x = now * j + now - 1;
			if (x <= get(x) * now)
				ss.insert(x);
			else
				break;
		}
	}
	ss.erase(0);
	int k;
	cin >> k;
	for (ll x: ss){
		cout << x << "\n";
		--k;
		if (k == 0)
			break;
	}
	return 0;
}


