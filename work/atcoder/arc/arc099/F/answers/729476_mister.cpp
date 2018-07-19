#include <bits/stdc++.h>
using namespace std;
#define db(x) cerr << #x << "=" << x << endl
#define db2(x, y) cerr << #x << "=" << x << "," << #y << "=" << y << endl
#define db3(x, y, z) cerr << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z << endl
#define dbv(v) cerr << #v << "="; for (auto x : v) cerr << x << ", "; cerr << endl
#define dba(a, n) cerr << #a << "="; for (int i = 0; i < (n); ++i) cerr << a[i] << ", "; cerr << endl
typedef long long ll;
typedef long double ld;
char S[250005];
const ll P = 998244353;
const ll Q = 400009;
const ll P2 = 1000000007;
const ll Q2 = 400033;
ll modex(ll a, ll p, ll m) {
	if (!p) return 1;
	if (p & 1) return a * modex(a, p - 1, m) % m;
	ll v = modex(a, p >> 1, m);
	return v * v % m;
}
int main() {
	int n;
	scanf("%d%s", &n, S);
	ll Qinv = modex(Q, P - 2, P);
	ll Qinv2 = modex(Q2, P2 - 2, P2);
	ll v = 0, v2 = 0;
	for (int i = n - 1; i >= 0; --i) {
		if (S[i] == '+') v = (v + 1) % P;
		else if (S[i] == '-') v = (v - 1) % P;
		else if (S[i] == '>') v = v * Q % P;
		else if (S[i] == '<') v = v * Qinv % P;
		if (S[i] == '+') v2 = (v2 + 1) % P2;
		else if (S[i] == '-') v2 = (v2 - 1) % P2;
		else if (S[i] == '>') v2 = v2 * Q2 % P2;
		else if (S[i] == '<') v2 = v2 * Qinv2 % P2;
	}
	if (v < 0) v += P;
	if (v2 < 0) v2 += P2;
	map<pair<ll, ll>, int> cnt;
	ll mult = 1, add = 0, multinv = 1;
	ll mult2 = 1, add2 = 0, multinv2 = 1;
	ll ans = 0;
	for (int i = n - 1; i >= 0; --i) {
		// add 0
		// x * mult + add = 0
		ll zero = -add * multinv % P;
		if (zero < 0) zero += P;
		ll zero2 = -add2 * multinv2 % P2;
		if (zero2 < 0) zero2 += P2;
		++cnt[{zero, zero2}];
		if (S[i] == '+') add = (add + 1) % P;
		else if (S[i] == '-') add = (add - 1) % P;
		else if (S[i] == '>') {
			mult = mult * Q % P;
			multinv = multinv * Qinv % P;
			add = add * Q % P;
		} else if (S[i] == '<') {
			mult = mult * Qinv % P;
			multinv = multinv * Q % P;
			add = add * Qinv % P;	
		}
		if (S[i] == '+') add2 = (add2 + 1) % P2;
		else if (S[i] == '-') add2 = (add2 - 1) % P2;
		else if (S[i] == '>') {
			mult2 = mult2 * Q2 % P2;
			multinv2 = multinv2 * Qinv2 % P2;
			add2 = add2 * Q2 % P2;
		} else if (S[i] == '<') {
			mult2 = mult2 * Qinv2 % P2;
			multinv2 = multinv2 * Q2 % P2;
			add2 = add2 * Qinv2 % P2;	
		}
		// query how many is equal to v
		ll w = (v - add) * multinv % P;
		if (w < 0) w += P;
		ll w2 = (v2 - add2) * multinv2 % P2;
		if (w2 < 0) w2 += P2;
		auto it = cnt.find(make_pair(w, w2));
		if (it != cnt.end()) ans += it->second;
	}
	printf("%lld\n", ans);
}
