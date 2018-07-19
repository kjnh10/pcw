#include "bits/stdc++.h"

#define REP(i,n) for(ll i=0;i<n;++i)
#define RREP(i,n) for(ll i=n-1;i>=0;--i)
#define FOR(i,m,n) for(ll i=m;i<n;++i)
#define RFOR(i,m,n) for(ll i=n-1;i>=m;--i)
#define ALL(v) (v).begin(),(v).end()
#define PB(a) push_back(a)
#define UNIQUE(v) v.erase(unique(ALL(v),v.end()));
#define DUMP(v) REP(i, (v).size()) { cout << v[i]; if (i != v.size() - 1)cout << " "; else cout << endl; }
#define INF 1000000001ll
#define MOD 1000000007ll
#define EPS 1e-9

const int dx[8] = { 1,1,0,-1,-1,-1,0,1 };
const int dy[8] = { 0,1,1,1,0,-1,-1,-1 };


using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
///(´・ω・`)(´・ω・`)(´・ω・`)(´・ω・`)(´・ω・`)(´・ω・`)///
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	ll sx=0, sy=0, tx=0, ty=0;
	vector<pll> s(n), t(n);
	REP(i, n) {
		ll x, y;
		cin >> x >> y;
		s[i] = { x,y };
		sx += x;
		sy += y;
	}
	REP(i, n) {
		ll x, y;
		cin >> x >> y;
		t[i] = { x,y };
		tx += x;
		ty += y;
	}
	double SX=double(sx)/n, SY=double(sy)/n, TX=double(tx)/n, TY=double(ty)/n;
	double smax = -1, tmax = -1;
	REP(i, n) {
		double tmp = sqrt((s[i].first - SX)*(s[i].first - SX) + (s[i].second - SY)*(s[i].second - SY));
		smax = max(tmp, smax);
	}
	REP(i, n) {
		double tmp = sqrt((t[i].first - TX)*(t[i].first - TX) + (t[i].second - TY)*(t[i].second - TY));
		tmax = max(tmp, tmax);
	}
	cout << setprecision(12) << tmax / smax << endl;
	return 0;
}
