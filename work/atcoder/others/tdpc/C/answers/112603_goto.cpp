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

int dd[1919];

vector<double> solve(int b, int e) {
	vector<double> r(e - b, 0.0);
	if(b == e - 1) {
		r[0] = 1.0;
	}
	else {
		int m = (b + e) / 2;
		auto w1 = solve(b, m);
		auto w2 = solve(m, e);
		rep(i, w1.size()) {
			rep(j, w2.size()) {
				double k = 1.0 / (1.0 + pow(10.0, (double)(dd[m + j] - dd[b + i]) / 400.0));
				r[i] += w1[i] * w2[j] * k;
				r[m + j - b] += w1[i] * w2[j] * (1.0 - k);
			}
		}
	}
	return r;
}

signed main() {
	int dk;
	cin >> dk;
	rep(i, (1 << dk)) {
		cin >> dd[i];
	}
	auto ans = solve(0, (1 << dk));
	rep(i, (1 << dk)) {
		printf("%.10lf\n", ans[i]);
	}
}
