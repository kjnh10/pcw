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
	int n, m;
	cin >> n >> m;
	vector<int> f(n);
	vector<int> p(m, -1);
	REP(i, n) {
		cin >> f[i];
		f[i]--;
	}
	int j = 0;
	vector<int> dp(n + 1);
	dp[0] = 1;
	vector<int> acum(n + 1);
	acum[0] = 1;
	REP(i, n) {
		if (p[f[i]] != -1 && p[f[i]] > j) {
			while (j != p[f[i]]) {
				j++;
			}
		}
		p[f[i]] = i + 1;
		if (j >= 1)dp[i + 1] = (acum[i] - acum[j - 1] + MOD) % MOD;
		else dp[i + 1] = acum[i] % MOD;
		acum[i + 1] += (acum[i] + dp[i + 1]) % MOD;

	}
	cout << dp[n] % MOD << endl;
	return 0;
}
