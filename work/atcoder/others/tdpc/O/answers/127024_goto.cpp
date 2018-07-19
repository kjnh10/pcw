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

int dp[300];
int dpw[300];

int rui[300];

int pow(int x, int n) {
	int r = 1;
	while(n > 0) {
		if(n & 1) {
			r = r * x % mod;
		}
		x = x * x % mod;
		n /= 2;
	}
	return r;
}

int inv(int x) {
	return pow(x, mod - 2);
}

int comb(int n, int x) {
	if(n < x) {
		return 0;
	}
	return rui[n] * inv(rui[n - x]) % mod * inv(rui[x]) % mod;
}

signed main() {
	rep(i, 300) {
		dp[i] = 0;
	}
	rui[0] = 1;
	mfor(i, 1, 300) {
		rui[i] = rui[i - 1] * i % mod;
	}
	bool f = true;
	int nk = 0;
	rep(__, 26) {
		int w;
		cin >> w;
		if(w > 0) {
			if(f) {
				dp[w - 1] = 1;
				nk = w;
				f = false;
			}
			else {
				rep(i, 300) {
					dpw[i] = 0;
				}
				trep(i, nk - 1) {
					rep1(j, w) {
						int s = comb(w - 1, j - 1);
						trep(_, min(i, j)) {
							dpw[i - _ + w - j] += dp[i] * s % mod * comb(i, _) % mod * comb(nk + 1 - i, j - _) % mod;
						}
					}
				}
				rep(i, 300) {
					dp[i] = dpw[i] % mod;
				}
				nk += w;
			}
		}
	}
	cout << dp[0] << endl;
}
