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
//typedef vector<int> vi;
using namespace std;


int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> v(n);
	REP(i, n)cin >> v[i];

	int cmax = -INF;
	REP(i, n) {
		int amax = -INF;
		int score = -INF;
		RREP(j, n) {
			if (i == j)continue;
			int l = i, r = j;
			if (l > r)swap(l, r);
			int atmp = 0, ctmp = 0;
			REP(k, r - l + 1) {
				if (k % 2 == 0)ctmp += v[k+l];
				else atmp += v[k+l];
			}
			if (atmp >= amax) {
				amax = atmp;
				score = ctmp;
			}
		}
		cmax = max(cmax, score);
	}

	cout << cmax << endl;
	
	return 0;
}
