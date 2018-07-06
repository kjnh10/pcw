#include <bits/stdc++.h>
using namespace std;

#define int long long

#define inf 1000000007LL
#define mod 1000000007LL

#define rep(i, n) for(int i = 0; i < (n); i++)
#define trep(i, n) for(int i = 0; i <= (n); i++)
#define rrep(i, n) for(int i = (n) - 1; i >= 0; i--)
#define rep1(i, n) for(int i = 1; i <= (n); i++)
#define mfor(i, s, t) for(int i = (s); i < (t); i++)
#define tfor(i, s, t) for(int i = (s); i <= (t); i++)
#define rfor(i, s, t) for(int i = (t) - 1; i >= (s); i--)

bool dv[20][20];

int dp[20][20];
int dd[20][20];

int md[20][20];

int tmp[1 << 16][20];

signed main() {
	int dh, dr;
	cin >> dh >> dr;
	rep(i, dr) {
		rep(j, dr) {
			cin >> dv[i][j];
		}
	}
	rep(i, dr) {
		rep(j, 1 << dr) {
			rep(k, dr) {
				tmp[j][k] = 0;
			}
		}
		rep(j, dr) {
			dp[i][j] = 0;
		}
		tmp[1 << i][i] = 1;
		dp[i][i] = 1;
		rep(j, 1 << dr) {
			rep(_, dr) {
				rep(k, dr) {
					if(dv[_][k]) {
						if(j & (1 << k)) {
							tmp[j][k] = (tmp[j][k] + tmp[j ^ (1 << k)][_]) % mod;
							dp[i][k] = (dp[i][k] + tmp[j ^ (1 << k)][_]) % mod;
						}
					}
				}
			}
		}
	}
	rep(i, dr) {
		rep(j, dr) {
			dd[i][j] = 0;
		}
	}
	dd[0][0] = 1;
	while(dh > 0) {
		if(dh & 1) {
			rep(i, dr) {
				rep(j, dr) {
					md[i][j] = 0;
					rep(k, dr) {
						md[i][j] = (md[i][j] + dd[i][k] * dp[k][j]) % mod;
					}
				}
			}
			rep(i, dr) {
				rep(j, dr) {
					dd[i][j] = md[i][j];
				}
			}
		}
		rep(i, dr) {
			rep(j, dr) {
				md[i][j] = 0;
				rep(k, dr) {
					md[i][j] = (md[i][j] + dp[i][k] * dp[k][j]) % mod;
				}
			}
		}
		rep(i, dr) {
			rep(j, dr) {
				dp[i][j] = md[i][j];
			}
		}
		dh /= 2;
	}
	cout << dd[0][0] << endl;
}
