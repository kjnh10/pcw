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

string ds;

int dp[334][334];

int solve(int b, int e) {
	if(dp[b][e] < 0) {
		if(e - b < 3) {
			dp[b][e] = 0;
		}
		else if(e - b == 3) {
			if(ds[b] == 'i' && ds[b + 1] == 'w' && ds[b + 2] == 'i') {
				dp[b][e] = 1;
			}
			else {
				dp[b][e] = 0;
			}
		}
		else {
			dp[b][e] = 0;
			if(ds[b] == 'i' && ds[e - 1] == 'i') {
				mfor(i, b + 1, e - 1) {
					if(ds[i] == 'w' && solve(b + 1, i) * 3 == i - (b + 1) && solve(i + 1, e - 1) * 3 == (e - 1) - (i + 1)) {
						dp[b][e] = (e - b) / 3;
					}
				}
			}
			tfor(i, b + 1, e - 1) {
				dp[b][e] = max(dp[b][e], solve(b, i) + solve(i, e));
			}
		}
	}
	return dp[b][e];
}

signed main() {
	cin >> ds;
	trep(i, ds.size()) {
		trep(j, ds.size()) {
			dp[i][j] = -1;
		}
	}
	cout << solve(0, ds.size()) << endl;
}
