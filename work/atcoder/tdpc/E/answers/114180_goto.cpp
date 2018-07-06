#include <bits/stdc++.h>
using namespace std;

#define int long long

#define inf (int)1000000007
#define mod (int)1000000007

#define rep(i, n) for(int i = 0; i < (n); i++)
#define trep(i, n) for(int i = 0; i <= (n); i++)
#define rrep(i, n) for(int i = (n) - 1; i >= 0; i--)
#define rep1(i, n) for(int i = 1; i <= (n); i++)
#define mfor(i, s, t) for(int i = (s); i < (t); i++)
#define tfor(i, s, t) for(int i = (s); i <= (t); i++)
#define rfor(i, s, t) for(int i = (t) - 1; i >= (s); i--)

int dp[2][114];
int dpw[2][114];

signed main() {
	int dd;
	cin >> dd;
	string ds;
	cin >> ds;
	rep(i, dd) {
		dp[0][i] = 0;
		dp[1][i] = 0;
	}
	dp[0][0] = 1;
	for(auto iw : ds) {
		int i = iw - '0';
		rep(j, dd) {
			dpw[0][j] = 0;
			dpw[1][j] = 0;
		}
		rep(j, dd) {
			rep(k, 10) {
				if(k < i) {
					dpw[1][(j + k) % dd] += dp[0][j] + dp[1][j];
				}
				else if(k == i) {
					dpw[0][(j + k) % dd] += dp[0][j];
					dpw[1][(j + k) % dd] += dp[1][j];
				}
				else {
					dpw[1][(j + k) % dd] += dp[1][j];
				}
			}
		}
		rep(j, dd) {
			dp[0][j] = dpw[0][j] % mod;
			dp[1][j] = dpw[1][j] % mod;
		}
	}
	cout << (dp[0][0] + dp[1][0] + mod - 1) % mod << endl;
}
