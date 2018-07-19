#include <bits/stdc++.h>
using namespace std;

#define int long long

#define inf (int)1000000007

#define rep(i, n) for(int i = 0; i < (n); i++)
#define trep(i, n) for(int i = 0; i <= (n); i++)
#define rrep(i, n) for(int i = (n) - 1; i >= 0; i--)
#define rep1(i, n) for(int i = 1; i <= (n); i++)
#define mfor(i, s, t) for(int i = (s); i < (t); i++)
#define tfor(i, s, t) for(int i = (s); i <= (t); i++)
#define rfor(i, s, t) for(int i = (t) - 1; i >= (s); i--)

double dp[222][111][111];
double dpw[222][111][111];

signed main() {
	int dn, dd;
	cin >> dn >> dd;
	int k2 = 0;
	int k3 = 0;
	int k5 = 0;
	while(dd > 0) {
		if(dd % 2 != 0) {
			break;
		}
		k2++;
		dd /= 2;
	}
	while(dd > 0) {
		if(dd % 3 != 0) {
			break;
		}
		k3++;
		dd /= 3;
	}
	while(dd > 0) {
		if(dd % 5 != 0) {
			break;
		}
		k5++;
		dd /= 5;
	}
	if(dd > 1) {
		cout << 0.0 << endl;
		return 0;
	}
	trep(i, dn * 2) {
		trep(j, dn) {
			trep(k, dn) {
				dp[i][j][k] = 0.0;
			}
		}
	}
	dp[0][0][0] = 1.0;
	rep(_, dn) {
		trep(i, dn * 2) {
			trep(j, dn) {
				trep(k, dn) {
					dpw[i][j][k] = 0.0;
				}
			}
		}
		trep(i, dn * 2) {
			trep(j, dn) {
				trep(k, dn) {
					dpw[i][j][k] += dp[i][j][k] / 6.0;
					dpw[i + 1][j][k] += dp[i][j][k] / 6.0;
					dpw[i][j + 1][k] += dp[i][j][k] / 6.0;
					dpw[i + 2][j][k] += dp[i][j][k] / 6.0;
					dpw[i][j][k + 1] += dp[i][j][k] / 6.0;
					dpw[i + 1][j + 1][k] += dp[i][j][k] / 6.0;
				}
			}
		}
		trep(i, dn * 2) {
			trep(j, dn) {
				trep(k, dn) {
					dp[i][j][k] = dpw[i][j][k];
				}
			}
		}
	}
	double ans = 0.0;
	trep(i, dn * 2) {
		trep(j, dn) {
			trep(k, dn) {
				if(i >= k2 && j >= k3 && k >= k5) {
					ans += dp[i][j][k];
				}
			}
		}
	}
	printf("%.10lf\n", ans);
}
