#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll maxn = 1e18;

int main() {
	/* freopen("input.in", "r", stdin);
	freopen("output.o", "w", stdout); */
	ll h, w;
	scanf("%lld %lld", &h, &w);
	ll a1, a2, a3;
	ll ans = maxn;
	ll totarea = h * w;
	for (ll i = 1; i <= h; i++) {
		a1 = i * w;
		ll tmp = totarea - a1;
		if (tmp % 2 == 0) {
			a2 = tmp / 2;
			a3 = tmp / 2;
		} else {
			ll diff = min(h-i, w);
			a2 = (tmp - diff) / 2;
			a3 = a2 + diff;
		}
		ll minn = min(min(a1, a2), a3);
		ll maxx = max(max(a1, a2), a3);
		ans = min(ans, maxx - minn);
	}
	ll pls;
	pls = h;
	h = w;
	w = pls;
	for (ll i = 1; i <= h; i++) {
		a1 = i * w;
		ll tmp = totarea - a1;
		if (tmp % 2 == 0) {
			a2 = tmp / 2;
			a3 = tmp / 2;
		} else {
			ll diff = min(h-i, w);
			a2 = (tmp - diff) / 2;
			a3 = a2 + diff;
		}
		ll minn = min(min(a1, a2), a3);
		ll maxx = max(max(a1, a2), a3);
		ans = min(ans, maxx - minn);
	}
	printf("%lld", ans);
}