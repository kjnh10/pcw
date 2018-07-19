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

class Uf {
	public:
	vector<int> o, r;
	vector<pair<int, int>> d;
	void init(int n) {
		o = vector<int>(n * 2 + 1, -1);
		r = vector<int>(n * 2 + 1, 0);
		d = vector<pair<int, int>>(n * 2 + 1, make_pair(inf, -inf));
		trep(i, n) {
			d[n + i] = make_pair(i, i);
		}
	}
	int find(int a) {
		if(o[a] < 0) {
			return a;
		}
		return o[a] = find(o[a]);
	}
	void unite(int a, int b) {
		a = find(a);
		b = find(b);
		if(a != b) {
			if(r[a] > r[b]) {
				o[b] = a;
				d[a] = make_pair(min(d[a].first, d[b].first), max(d[a].second, d[b].second));
			}
			else if(r[a] == r[b]) {
				o[b] = a;
				r[a]++;
				d[a] = make_pair(min(d[a].first, d[b].first), max(d[a].second, d[b].second));
			}
			else {
				o[a] = b;
				d[b] = make_pair(min(d[a].first, d[b].first), max(d[a].second, d[b].second));
			}
		}
	}
	pair<int, int> get(int a) {
		return d[find(a)];
	}
} uf;

int unite(int h, int a, int b) {
	uf.init(h);
	stack<int> st;
	rep(i, h) {
		int w = a >> i * 2 & 3;
		if(w > 0 && (b & 1 << i)) {
			uf.unite(i, i + h);
		}
		if(w == 1) {
			st.push(i);
		}
		else if(w == 2) {
			assert(!st.empty());
			uf.unite(st.top(), i);
			st.top() = i;
		}
		else if(w == 3) {
			assert(!st.empty());
			uf.unite(st.top(), i);
			st.pop();
		}
	}
	assert(st.size() == 1);
	uf.unite(st.top(), h * 2);
	rep(i, h - 1) {
		if((b & 1 << i) && (b & 1 << i + 1)) {
			uf.unite(i + h, i + 1 + h);
		}
	}
	bool ok = false;
	int ret = 0;
	rep(i, h) {
		auto w = uf.get(i + h);
		if(w.first < w.second) {
			if(w.first == i) {
				ret += 1 << i * 2;
			}
			else if(w.second == i) {
				ret += 3 << i * 2;
			}
			else {
				ret += 2 << i * 2;
			}
		}
		if(w.second == h) {
			ok = true;
		}
	}
	if(ok) {
		return ret;
	}
	else {
		return 0;
	}
}
 
int dp[1 << 12];
int dp_[1 << 12];
 
signed main() {
	int dh, dw;
	cin >> dh >> dw;
	rep(i, 1 << dh * 2) {
		dp[i] = 0;
	}
	dp[1] = 1;
	rep(_, dw) {
		rep(i, 1 << dh * 2) {
			dp_[i] = 0;
		}
		rep(i, 1 << dh * 2) {
			rep(j, 1 << dh) {
				if(dp[i] > 0) {
					int w = unite(dh, i, j);
					if(w > 0) {
						dp_[w] += dp[i];
					}
				}
			}
		}
		rep(i, 1 << dh * 2) {
			dp[i] = dp_[i] % mod;
		}
	}
	int ans = 0;
	rep(i, 1 << dh * 2) {
		if(dp[i] > 0) {
			int w = i >> (dh - 1) * 2;
			if(w == 1 || w == 2) {
				ans += dp[i];
			}
		}
	}
	cout << ans % mod << endl;
}
