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

vector<int> dv[1919];

pair<vector<int>, vector<int>> solve(int k, int o, int p) {
	vector<int> dp1(k + 1, 0), dp2(k + 1, 0), dp3(k + 1, 0);
	dp1[0] = 1;
	for(auto _ : dv[p]) {
		if(_ != o) {
			auto w = solve(k, p, _);
			vector<int> dp1_(k + 1, 0), dp2_(k + 1, 0), dp3_(k + 1, 0);
			trep(i, k) {
				trep(j, k) {
					if(i + j <= k) {
						dp1_[i + j] = (dp1_[i + j] + dp1[i] * w.first[j]) % mod;
						dp2_[i + j] = (dp2_[i + j] + dp2[i] * w.first[j] + dp1[i] * w.second[j]) % mod;
						dp3_[i + j] = (dp3_[i + j] + dp3[i] * w.first[j]) % mod;
					}
					if(0 <= i + j - 1 && i + j - 1 <= k) {
						dp3_[i + j - 1] = (dp3_[i + j - 1] + dp2[i] * w.second[j]) % mod;
					}
				}
			}
			dp1 = dp1_;
			dp2 = dp2_;
			dp3 = dp3_;
		}
	}
	vector<int> r1(k + 1, 0), r2(k + 1, 0);
	trep(i, k) {
		r1[i] = (dp1[i] + dp2[i] + dp3[i]) % mod;
	}
	rep1(i, k) {
		r2[i] = (dp1[i - 1] + dp2[i]) % mod;
	}
	return make_pair(r1, r2);
}

signed main() {
	int dn, dk;
	cin >> dn >> dk;
	rep(i, dn - 1) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		dv[a].push_back(b);
		dv[b].push_back(a);
	}
	cout << solve(dk, -1, 0).first[dk] << endl;
}
