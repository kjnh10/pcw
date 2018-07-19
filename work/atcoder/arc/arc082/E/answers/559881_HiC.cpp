#include <bits/stdc++.h>

typedef long long ll;
typedef long long llong;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;

const ll MOD = 998244353;
ll pw(ll a, ll b) {
	ll ans = 1; while (b) {
		while (!(b & 1)) b >>= 1, a = (a * a) % MOD;
		ans = (ans * a) % MOD, --b;
	} return ans;
}

struct point {
	ll x, y;
	point operator-(point a) {
		return {x - a.x, y - a.y};
	}
	ll operator*(point a) {
		return x * a.y - y * a.x;
	}
	bool operator<(point a) {
		return make_pair(x, y) < make_pair(a.x, a.y);
	}
};

int n;
point a[300];


int main() {
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i].x >> a[i].y;
	ll ans = 1;
	for (int i = 0; i < n; ++i)
		ans = ans * 2 % MOD;
	ans = (ans - 1 + MOD) % MOD;
	ans = (ans - n + MOD) % MOD;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) {
			if (!(a[i] < a[j]))
				continue;
			int cc = 0;
			for (int k = 0; k < n; ++k)
				if (a[i] < a[k] && a[k] < a[j] && (a[k] - a[i]) * (a[j] - a[i]) == 0)
					++cc;
			ll mn = pw(2, cc);
			ans = (ans - mn + MOD) % MOD;
		}
	cout << ans << "\n";
	return 0;
}


