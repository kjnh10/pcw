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
	int r, c, k;
	cin >> r >> c >> k;
	vector<string> s(r);
	vector<vector<pair<int,int>>> v(r, vector<pair<int,int>>(c));
	REP(i, r)cin >> s[i];
	REP(i, r) {
		int cnt = 0;
		REP(j, c) {
			if (s[i][j] == 'o')	cnt++;
			else cnt = 0;
			v[i][j].first = cnt;
		}
	}
	RREP(i, r) {
		int cnt = 0;
		RREP(j, c) {
			if (s[i][j] == 'o')	cnt++;
			else cnt = 0;
			v[i][j].second = cnt;
		}
	}
	int ans = 0;
	FOR(y, k-1,r-k+1) {
		FOR(x,k-1,c-k+1) {
			int flag = 1;
			FOR(i, -k+1, k) {
				if (min(v[y + i][x].first, v[y + i][x].second) < k - abs(i))flag = 0;
			}
			if (flag)ans++;
		}
	}
	cout << ans << endl;
	return 0;
}
