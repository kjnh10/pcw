#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
#define ll long long int
#define ld long double
#define pb push_back
#define mkp make_pair
#define pii pair<int, int> 
#define pll pair<long long int, long long int>
#define sci(x) scanf("%d", &x)
#define scl(x) scanf("%lld", &x)
#define fi first
#define sc second
#define deb 0

ll fact[100001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	ll n, m, ans = 0, i, x, y;
	cin >> n >> m;
	fact[0] = 1;
	for (i = 1; i <= 100000; ++i) {
		fact[i] = (i * fact[i-1]) % MOD;
	}

	if (m == n || m == n+1) {
		x = (fact[m] * fact[n]) % MOD;
	} else x = 0;
	if (n == m || n == m+1) {
		y = (fact[n] * fact[m]) % MOD;
	} else y = 0;
	ans = (x + y) % MOD;
	cout << ans << endl;

	return 0;
}