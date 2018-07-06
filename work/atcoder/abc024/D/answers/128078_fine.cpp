#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 1000000007;

ll modpow(ll x, ll n) {
	ll res = 1;
	while (n > 0) {
		if (n & 1) res = res * x % MOD;
		x = x * x % MOD;
		n >>= 1;
	}
	return res;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll A, B, C;
	cin >> A >> B >> C;
	ll x = A * ((B + C) % MOD) % MOD - B * C % MOD;
	(x += MOD) %= MOD;
	ll y = B * ((C - A + MOD) % MOD) % MOD;
	ll c = modpow(x, MOD - 2) * y % MOD;
	ll r = modpow(A, MOD - 2) * ((B - A + MOD) % MOD * ((c + 1) % MOD) % MOD) % MOD;
	cout << r << " " << c << endl; 
	return 0;
}