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

pair<int, int> dp[1919][1919];

int aa[1919];
int bb[1919];

pair<int, int> solve(int a, int b) {
	if(dp[a][b].first < 0) {
		if(a == 0 && b == 0) {
			dp[a][b] = make_pair(0, 0);
		}
		else if(a == 0) {
			auto w = solve(0, b - 1);
			dp[a][b] = make_pair(w.second + bb[b], w.first);
		}
		else if(b == 0) {
			auto w = solve(a - 1, 0);
			dp[a][b] = make_pair(w.second + aa[a], w.first);
		}
		else {
			auto w1 = solve(a - 1, b);
			auto w2 = solve(a, b - 1);
			dp[a][b] = max(make_pair(w1.second + aa[a], w1.first), make_pair(w2.second + bb[b], w2.first));
		}
	}
	return dp[a][b];
}

signed main() {
	int da, db;
	cin >> da >> db;
	rep(i, da) {
		cin >> aa[da - i];
	}
	rep(i, db) {
		cin >> bb[db - i];
	}
	trep(i, da) {
		trep(j, db) {
			dp[i][j] = make_pair(-1, -1);
		}
	}
	cout << solve(da, db).first << endl;
}
