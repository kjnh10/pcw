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

int gcd(int a, int b) {
	if (a%b == 0)return b;
	else return gcd(b, a%b);
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int a, b, n;
	cin >> a >> b >> n;
	if (a < b)swap(a, b);
	int p = a*b / gcd(a, b);
	FOR(i, 1, INF) {
		if (i * p >= n) {
			cout << i*p << endl;
			return 0;
		}
	}
}