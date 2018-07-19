#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define forn(i, a, n) for (int i = a; i < n; ++i)
#define ford(i, a, n) for (int i = n - 1; i >= a; --i)
#define fore(i, a, n) for (int i = a; i <= n; ++i)
#define all(a) (a).begin(), (a).end()
#define fs first
#define sn second
#define trace(a)\
	for (auto i : a) cerr << i << ' ';\
	cerr << '\n'
#define eb emplace_back

#ifndef M_PI
const ld M_PI = acos(-1.0);
#endif

const ld eps = 1e-9;
const int INF = 2000000000;
const ll LINF = 1ll * INF * INF;
const ll MOD = 1000000007;

const int N = 5010;

ll dp[N][N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	string s;
	cin >> s;
	int k = s.length();
	dp[0][0] = 1;
	forn(i, 1, N) {
		dp[i][0] = (dp[i - 1][0] + 2 * dp[i - 1][1]) % MOD;
		forn(j, 1, N) {
			dp[i][j] = dp[i - 1][j - 1];
			if (j != N - 1) dp[i][j] += 2 * dp[i - 1][j + 1];
			dp[i][j] %= MOD;
		}
	}
	cout << dp[n][k] << '\n';
	return 0;
}
