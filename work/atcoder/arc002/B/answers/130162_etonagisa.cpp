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
///(´・ω・`)(´・ω・`)(´・ω・`)(´・ω・`)(´・ω・`)(´・ω・`)///

bool isuru(int y) {
	bool ret = false;
	if (y % 4 == 0)ret = true;
	if (y % 100 == 0)ret = false;
	if (y % 400 == 0)ret = true;
	return ret;
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	vi v = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int y, m, d;
	cin >> y;
	cin.ignore();
	cin >> m;
	cin.ignore();
	cin>> d;
	while (1) {
		if (y%m == 0 && y/m %d == 0) {
			cout << y << '/' << setw(2) << setfill('0') << m << '/' << setw(2) << setfill('0') << d << endl;
			break;
		}
		if (v[m - 1] == d) {
			if (isuru(y) && m == 2) {
				d++;
				if (y%m == 0 && y / m%d == 0) {
					cout << y << '/' << setw(2) << setfill('0') << m << '/' << setw(2) << setfill('0') << d << endl;
					break;
				}
				else {
					m++;
					d = 1;
				}
			}
			else {
				m++;
				d = 1;
				if (m == 13) {
					m = 1;
					y++;
				}
			}
		}
		else d++;
	}
	return 0;
}