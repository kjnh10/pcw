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

int pow(int x, int p) {
	int r = 1;
	while(p > 0) {
		if(p & 1) {
			r = r * x % mod;
		}
		x = x * x % mod;
		p /= 2;
	}
	return r;
}

int inv(int x) {
	return pow(x, mod - 2);
}

int rui[1919];

int comb(int n, int x) {
	return rui[n] * inv(rui[n - x]) % mod * inv(rui[x]) % mod;
}

pair<int, int> solve(int o, int p) {
	int r = 1;
	int h = 0;
	for(auto i : dv[p]) {
		if(i != o) {
			auto w = solve(p, i);
			r = r * w.first % mod * comb(h + w.second, w.second) % mod;
			h += w.second;
		}
	}
	return make_pair(r, h + 1);
}

signed main() {
	int dn;
	cin >> dn;
	rep(i, dn - 1) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		dv[a].push_back(b);
		dv[b].push_back(a);
	}
	rui[0] = 1;
	rep1(i, dn) {
		rui[i] = rui[i - 1] * i % mod;
	}
	int ans = 0;
	rep(i, dn) {
		ans = (ans + solve(-1, i).first) % mod;
	}
	cout << (ans * inv(2)) % mod << endl;
}
