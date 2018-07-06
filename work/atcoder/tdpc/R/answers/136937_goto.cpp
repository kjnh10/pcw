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

vector<int> v[514];

int sn = 0;
int sccn[514];
int scc[514];

int mt = 0;
int low[514];
stack<int> st;

int scc_solve(int p) {
	if(low[p] < 0) {
		int w = low[p] = mt++;
		st.push(p);
		for(auto i : v[p]) {
			low[p] = min(low[p], scc_solve(i));
		}
		if(w == low[p]) {
			sccn[sn] = 0;
			while(1) {
				int n = st.top(); st.pop(); low[n] = inf;
				scc[n] = sn; sccn[sn]++;
				if(n == p) {
					break;
				}
			}
			sn++;
		}
	}
	return low[p];
}

vector<int> v2[514];
int rem[514];

int tpsn = 0;
int tps[514];

void tps_solve(int p) {
	if(rem[p] == 0) {
		tps[p] = tpsn++;
		for(auto i : v2[p]) {
			rem[i]--;
			tps_solve(i);
		}
	}
}

int dp[514][514];

int solve(int a, int b) {
	if(dp[a][b] < 0) {
		if(a == b) {
			dp[a][b] = sccn[a];
			for(auto i : v2[a]) {
				dp[a][b] = max(dp[a][b], solve(i, b));
			}
		}
		else {
			dp[a][b] = sccn[a] + sccn[b];
			if(v2[a].empty()) {
				for(auto i : v2[b]) {
					dp[a][b] = max(dp[a][b], sccn[b] + solve(a, i));
				}
			}
			else if(v2[b].empty()) {
				for(auto i : v2[a]) {
					dp[a][b] = max(dp[a][b], sccn[a] + solve(i, b));
				}
			}
			else {
				if(tps[a] < tps[b]) {
					for(auto i : v2[a]) {
						dp[a][b] = max(dp[a][b], sccn[a] + solve(i, b));
					}
				}
				else {
					dp[a][b] = solve(b, a);
				}
			}
		}
	}
	return dp[a][b];
}

signed main() {
	int dn;
	cin >> dn;
	rep(i, dn) {
		rep(j, dn) {
			int w;
			cin >> w;
			if(w) {
				v[i].push_back(j);
			}
		}
	}
	rep(i, dn) {
		low[i] = -1;
	}
	rep(i, dn) {
		scc_solve(i);
	}
	rep(i, sn) {
		rem[i] = 0;
	}
	rep(i, dn) {
		for(auto j : v[i]) {
			if(scc[i] != scc[j]) {
				v2[scc[i]].push_back(scc[j]);
				rem[scc[j]]++;
			}
		}
	}
	rep(i, sn) {
		tps_solve(i);
	}
	rep(i, sn) {
		rep(j, sn) {
			dp[i][j] = -1;
		}
	}
	int ans = 0;
	rep(i, sn) {
		rep(j, sn) {
			ans = max(ans, solve(i, j));
		}
	}
	cout << ans << endl;
}
