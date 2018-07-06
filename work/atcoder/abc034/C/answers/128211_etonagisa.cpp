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


using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
///(´・ω・`)(´・ω・`)(´・ω・`)(´・ω・`)(´・ω・`)(´・ω・`)///


ll mod_mult(ll a, ll n, ll m) { //a*nMODm
	a %= m;
	if (a < 0) a += m;
	ll ans = 0;
	while (n >= 1) {
		if (n % 2 == 1) ans = (a + ans) % m;
		a = a * 2 % m;
		n >>= 1;
	}
	return ans;
}
ll mod_pow(ll a, ll n, ll m) {//a^n MOD m
	ll b = 1;
	while (n >= 1) {
		if (n % 2 == 1) b = mod_mult(a, b, m);
		a = mod_mult(a, a, m);
		n >>= 1;
	}
	return b;
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int w, h;
	cin >> w >> h;
	ll n = w + h;
	vl fact(n);
	fact[0] = 1;
	REP(i, n-1) {
		fact[i + 1] = fact[i] * (i + 1) % MOD;
	}
	vector<long long> e(w+h);
	e[n-1] = mod_pow(fact[n-1], MOD - 2, MOD);
	RREP(i, n-1) {
		e[i] = (i + 1)*e[i + 1] % MOD;
	}
	cout << fact[w + h - 2] * e[w - 1] % MOD*e[h - 1] % MOD << endl;

	return 0;
}
