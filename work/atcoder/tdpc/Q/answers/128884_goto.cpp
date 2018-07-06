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

bool dd[512];
int fir[512];

int dp[114][512][256];

signed main() {
	rep(i, 512) {
		dd[i] = false;
	}
	int dn, dl;
	cin >> dn >> dl;
	rep(i, dn) {
		string s;
		cin >> s;
		int w = 0;
		int k = 1;
		for(auto i : s) {
			w = w + (i - '0') * k;
			k *= 2;
		}
		dd[(1 << s.size()) + w] = true;
	}
	rep1(k, 8) {
		rep(i, 1 << k) {
			int w = 0;
			mfor(j, 1, k) {
				if(dd[(1 << j) + (i & (1 << j) - 1)]) {
					w += 1 << j;
				}
			}
			fir[(1 << k) + i] = w;
		}
	}
	rep1(k, 8) {
		rep(i, 1 << k) {
			rep(j, 1 << k) {
				dp[0][(1 << k) + i][j] = 0;
			}
		}
	}
	dp[0][0][0] = 1;
	rep1(s, dl) {
		rep1(k, 8) {
			rep(i, 1 << k) {
				rep(j, 1 << k) {
					int an = 0;
					if(j & 1) {
						if(dd[(1 << k) + i]) {
							an = 0;
						}
						else {
							int nex = j;
							mfor(_, 1, k) {
								if(dd[(1 << _) + (i & (1 << _) - 1)]) {
									nex |= 1 << _;
								}
							}
							if(k == 1) {
								an = dp[s - 1][0][0];
							}
							else {
								an = dp[s - 1][(1 << k) + i >> 1][nex >> 1];
							}
							rep1(_, 8 - k) {
								rep(u, 1 << _) {
									if(dd[(1 << k + _) + i + (u << k)]) {
										an -= dp[s - 1][(1 << k + _) + i + (u << k) >> 1][(nex | fir[(1 << k + _) + i + (u << k)]) >> 1] - dp[s - 1][(1 << k + _) + i + (u << k) >> 1][(nex | fir[(1 << k + _) + i + (u << k)]) + (1 << k) >> 1];
									}
								}
							}
						}
					}
					else {
						if(k == 1) {
							an = dp[s - 1][0][0];
						}
						else {
							an = dp[s - 1][(1 << k) + i >> 1][j >> 1];
						}
					}
					dp[s][(1 << k) + i][j] = (an % mod + mod) % mod;
				}
			}
		}
		dp[s][0][0] = 0;
		rep1(k, 8) {
			rep(i, 1 << k) {
				if(dd[(1 << k) + i]) {
					dp[s][0][0] = (dp[s][0][0] + dp[s][(1 << k) + i][fir[(1 << k) + i]]) % mod;
				}
			}
		}
	}
	cout << dp[dl][0][0] << endl;
}
