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

int dn;
int dd[16];

bool cul[1 << 16];
double dp[1 << 16];

double solve(int m) {
	if(!cul[m]) {
		cul[m] = true;
		dp[m] = inf;
		rep(i, dn) {
			tfor(j, -1, 1) {
				vector<double> v;
				rep(k, dn) {
					if((m & (1 << k)) && dd[i] + j - 1 <= dd[k] && dd[k] <= dd[i] + j + 1) {
						v.push_back(solve(m ^ (1 << k)));
					}
				}
				if(v.size() == 1) {
					dp[m] = min(dp[m], v[0] + 3.0);
				}
				else if(v.size() == 2) {
					dp[m] = min(dp[m], (v[0] + v[1]) / 2.0 + 1.5);
				}
				else if(v.size() == 3) {
					dp[m] = min(dp[m], (v[0] + v[1] + v[2]) / 3.0 + 1.0);
				}
			}
		}
	}
	return dp[m];
}

signed main() {
	cin >> dn;
	rep(i, dn) {
		cin >> dd[i];
	}
	rep(i, 1 << 16) {
		cul[i] = false;
	}
	cul[0] = true;
	dp[0] = 0;
	printf("%.10lf\n", solve((1 << dn) - 1));
}
