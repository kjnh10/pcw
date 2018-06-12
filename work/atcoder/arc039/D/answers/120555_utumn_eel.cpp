#include<bits/stdc++.h>
#define MOD 1000000007
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;

ll fact[500];
ll ppow(ll a) {
	ll b = MOD - 2;
	ll res = 1;
	while (b) {
		if (b & 1)res = (res*a) % MOD;
		a = (a*a) % MOD;
		b >>= 1;
	}
	return res;
}
ll comb(ll a, ll b) {//a人の中からb人選ぶ
	return (fact[a] * ppow((fact[a - b] * fact[b]) % MOD)) % MOD;
}
signed main() {
	ll n, k; scanf("%lld%lld", &n, &k);
	fact[0] = 1;
	for (int i = 1; i <= k + n; i++)fact[i] = (fact[i - 1] * i) % MOD;
	if (k < n) {
		printf("%lld\n", comb(k + n - 1, k));
		return 0;
	}
	k %= n;
	printf("%lld\n", comb(n, k));
}