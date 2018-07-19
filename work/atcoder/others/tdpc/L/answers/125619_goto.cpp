#include <bits/stdc++.h>
using namespace std;

#define int long long

#define inf (int)1000000007
#define mod (int)1000000007

#define rep(i, n) for(int i = 0; i < (n); i++)
#define trep(i, n) for(int i = 0; i <= (n); i++)
#define rrep(i, n) for(int i = (n) - 1; i >= 0; i--)
#define rtrep(i, n) for(int i = (n); i >= 0; i--)
#define rep1(i, n) for(int i = 1; i <= (n); i++)
#define mfor(i, s, t) for(int i = (s); i < (t); i++)
#define tfor(i, s, t) for(int i = (s); i <= (t); i++)
#define rfor(i, s, t) for(int i = (t) - 1; i >= (s); i--)

int dp[1919];

int dd[1919];
int mt[1919];

signed main() {
	int dn;
	cin >> dn;
	rep(i, dn) {
		cin >> dd[i];
	}
	dp[0] = 0;
	mfor(_, 1, dn) {
		rep(i, dn) {
			cin >> dd[i];
		}
		int now = 0;
		rrep(i, _) {
			now += dd[i];
			mt[i] = now;
		}
		now = -inf;
		rep(i, _) {
			now = max(now, dp[i]);
			dp[i] = now + mt[i];
		}
		dp[_] = now;
	}
	int ans = -inf;
	rep(i, dn) {
		ans = max(ans, dp[i]);
	}
	cout << ans * 2 << endl;
}
