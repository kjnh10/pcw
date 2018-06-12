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

int n;
vector<int> a, b, c;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		int x;
		scanf("%d", &x);
		a.push_back(x);
	}
	for (int i = 0; i < n; ++i) {
		int x;
		scanf("%d", &x);
		b.push_back(x);
	}
	for (int i = 0; i < n; ++i) {
		int x;
		scanf("%d", &x);
		c.push_back(x);
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	sort(c.begin(), c.end());
	ll ans = 0;
	for (int i: b) {
		int x = lower_bound(a.begin(), a.end(), i) - a.begin();
		int y = upper_bound(c.begin(), c.end(), i) - c.begin();
		y = c.size() - y;
		ans += ll(x) * y;
	}
	cout << ans << "\n";
	return 0;
}


