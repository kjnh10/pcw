#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <utility>
#include <cstdio>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <cmath>
#include <set>
#include <map>
#define my_abs(x) ((x) < 0 ? -(x) : (x))
#define mp std::make_pair
#define pb push_back
typedef long long ll; 
ll MOD, fact[3005], inv[3005], dp[3005][3005], pw[10000005];
inline ll quick_pow(ll a, int n, ll mod)
{
	ll res = 1; 
	while (n)
	{
		if (n & 1)
			res = res * a % mod; 
		a = a * a % mod; 
		n >>= 1; 
	}
	return res; 
}
inline ll C(int n, int m)
{
	return fact[n] * inv[m] % MOD * inv[n - m] % MOD; 
}
int main()
{
	// freopen("ARC096-E.in", "r", stdin); 
	int n; 
	scanf("%d%lld", &n, &MOD); 
	fact[0] = inv[0] = 1; 
	for (int i = 1; i <= n; i++)
	{
		fact[i] = fact[i - 1] * i % MOD; 
		inv[i] = quick_pow(fact[i], MOD - 2, MOD); 
	}
	pw[0] = 1; 
	for (int i = 1; i < 10000005; i++)
		pw[i] = pw[i - 1] * 2 % MOD; 
	ll ans = 0; 
	dp[1][1] = 1; 
	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
			dp[i][j] = (dp[i - 1][j - 1] + j * dp[i - 1][j]) % MOD;
	}
	for (int i = 0; i <= n; i++)
	{
		ll coef = 1; 
		for (int k = 1; k <= i; k++)
			(coef += pw[(n - i) * k] * (dp[i][k + 1] * (k + 1) % MOD + dp[i][k])) %= MOD; 
		(ans += C(n, i) * coef % MOD * quick_pow(2, quick_pow(2, n - i, MOD - 1), MOD) * (i & 1 ? -1 : 1)) %= MOD;
	}
	printf("%lld\n", (ans + MOD) % MOD);
	return 0; 
}
