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
	int r, c, k, n;
	cin >> r >> c >> k >> n;
	vector<int> row(r, 0), col(c, 0);
	vector<pair<int, int>> p(n);
	REP(i, n) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		row[a]++;
		col[b]++;
		p[i] = { a,b };
	}

	ll ans = 0;
	REP(i, n) {
		if (row[p[i].first] + col[p[i].second] == k)ans--;
		else if (row[p[i].first] + col[p[i].second] == k + 1)ans++;
	}
	sort(ALL(col));
	REP(i, r) {
		ll tmp = upper_bound(ALL(col), k - row[i]) - lower_bound(ALL(col), k - row[i]);
		ans += tmp;
	}


	cout << ans << endl;
	return 0;
}
