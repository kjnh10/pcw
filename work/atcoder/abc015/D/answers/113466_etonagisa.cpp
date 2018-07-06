#include "bits/stdc++.h"

#define REP(i,n) for(ll i=0;i<n;++i)
#define RREP(i,n) for(ll i=n-1;i>=0;--i)
#define FOR(i,m,n) for(ll i=m;i<n;++i)
#define RFOR(i,m,n) for(ll i=n-1;i>=m;--i)
#define ALL(v) (v).begin(),(v).end()
#define PB(a) push_back(a)
#define UNIQUE(v) v.erase(unique(ALL(V),v.end()));
#define DUMP(v) REP(i, (v).size()) { cout << v[i]; if (i != v.size() - 1)cout << " "; else cout << endl; }
#define INF 1000000001ll
#define MOD 1000000007ll
#define EPS 1e-9

const int dx[8] = { 1,1,0,-1,-1,-1,0,1 };
const int dy[8] = { 0,1,1,1,0,-1,-1,-1 };

typedef long long ll;
using namespace std;


int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int w, n, k;
	cin >> w >> n >> k;
	vector<int> a(n), b(n);
	REP(i, n) {
		cin >> a[i] >> b[i];
	}
	vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(w + 1, vector<int>(k + 1, (-1)*INF)));
	REP(i, n + 1)REP(j, w + 1)dp[i][j][0] = 0;
	REP(i, n + 1)REP(l,k+1)dp[i][0][l] = 0;
	REP(i, n) {
		REP(j, w + 1) {
			REP(l, k + 1) {
				if (j < a[i]||l==0) {
					dp[i + 1][j][l] = dp[i][j][l];
				}
				else {
					if (dp[i][j - a[i]][l-1] + b[i] <= dp[i][j][l]) {
						dp[i + 1][j][l] = dp[i][j][l];
					}
					else {
						dp[i + 1][j][l] = dp[i][j - a[i]][l-1] + b[i];
					}
				}
			}
		}
	}
	int ans = -1;
	REP(i, w+1) {
	     ans = max(ans, dp[n][i][k]);
	}
	cout << ans << endl;
	return 0;
}
