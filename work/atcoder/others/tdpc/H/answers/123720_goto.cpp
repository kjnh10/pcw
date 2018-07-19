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

int dp[51][19191][2];

vector<pair<int, int>> dd[51];

signed main() {
	int dn, dw, dc;
	cin >> dn >> dw >> dc;
	rep(i, dn) {
		int w, v, c;
		cin >> w >> v >> c;
		c--;
		dd[c].push_back(make_pair(w, v));
	}
	trep(i, dc) {
		trep(j, dw) {
			dp[i][j][0] = -inf;
			dp[i][j][1] = -inf;
		}
	}
	dp[0][0][0] = 0;
	trep(_, 50) {
		for(auto a : dd[_]) {
			rep1(i, dc) {
				rtrep(j, dw - a.first) {
					dp[i][j + a.first][1] = max(dp[i][j + a.first][1], max(dp[i][j][1], dp[i - 1][j][0]) + a.second);
				}
			}
		}
		trep(i, dc) {
			trep(j, dw) {
				dp[i][j][0] = max(dp[i][j][0], dp[i][j][1]);
				dp[i][j][1] = -inf;
			}
		}
	}
	int ans = -inf;
	trep(i, dc) {
		trep(j, dw) {
			ans = max(ans, dp[i][j][0]);
		}
	}
	cout << ans << endl;
}
