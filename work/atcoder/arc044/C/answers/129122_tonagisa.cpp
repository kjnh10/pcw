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
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	int flag = 1;
	for (int i = 2; i*i <= n; ++i) {
		if (n%i == 0)flag = 0;
	}
	if (n == 1) {
		cout << "Not Prime" << endl;
	}
	else if (flag) {
		cout << "Prime" << endl;
	}
	else {
		int sum = 0;
		int a = n;
		while (a > 0) {
			sum += a % 10;
			a /= 10;
		}
		if (sum % 3 != 0 && n % 2 != 0 && n % 5 != 0)cout << "Prime" << endl;
		else cout << "Not Prime" << endl;
	}
	return 0;
}
