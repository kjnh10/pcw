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

pair<int, int> dd[114514];

int dp[114514];

signed main() {
	int dn;
	cin >> dn;
	rep(i, dn) {
		int x, r;
		cin >> x >> r;
		dd[i] = make_pair(x - r, x + r);
	}
	sort(dd, dd + dn);
	map<int, int> mv;
	mv[-1] = 0;
	int ans = 0;
	rrep(i, dn) {
		auto u = mv.lower_bound(dd[i].second);
		auto l = u;
		l--;
		int w = l->second + 1;
		ans = max(ans, w);
		while(u != mv.end()) {
			if(u->second <= w) {
				auto t = u;
				t++;
				mv.erase(u);
				u = t;
			}
			else {
				break;
			}
		}
		mv[dd[i].second] = w;
	}
	cout << ans << endl;
}
