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
	int a, b;
	cin >> a >> b;
	if (b < a)swap(a, b);
	int ans = (b-a)/10;
	a += ans*10;
	if (b - a <= 3)ans += b - a;
	else if (b - a <= 7)ans += 1 + abs(b - a - 5);
	else ans += 1 + abs(b - a - 10);
	cout << ans << endl;
	
	return 0;
}
