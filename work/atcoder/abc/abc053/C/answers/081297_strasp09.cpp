#include <bits/stdc++.h>
#include <ratio>
const long long INF = LLONG_MAX / 2;
const long long MOD = 1000000007;
const long double PI = 3.1415926;
#define FOR(i, r, n) for(int i=(ll)(r); i<(ll)(n); i++) 
#define REP(i, n) FOR(i, (0), n)
#define ALL(r) r.begin(), r.end()
#define ll long long int
using namespace std;
vector<ll> v;
vector<pair<ll, ll>> vp;
vector<vector<ll>> vv(110, vector<ll>(50, 0));
vector<tuple<ll, ll, ll>> vt;
set<ll> st;
map<ll, ll> mp;

int main()
{
	ll n;
	cin >> n;
	ll mod = n % 11;
	ll ans = n / 11*2;
	if (mod >= 7) ans += 2;
	else if (mod > 0) ans++;
	cout << ans << endl;
}