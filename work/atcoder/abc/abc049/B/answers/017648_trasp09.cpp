#include <bits/stdc++.h>
const long long INF = LLONG_MAX / 2;
const long long MOD = 1000000007;
const long double PI = 3.1415926;
#define FOR(i, r, n) for(int i=(ll)(r); i<(ll)(n); i++) 
#define REP(i, n) FOR(i, (0), n)
#define ALL(v) (v).begin(),(v).end()
#define ll long long int
using namespace std;
ll ans = 0, sum = 0, n, k, counter = 0, w, h, m;
string s;
vector<ll> v;
vector<pair<ll, ll>> vp;
vector<vector<ll>> vv(50, vector<ll>(50, INF));
vector<tuple<ll, ll, ll>> vt;
map<ll, ll> mp;

int main()
{
	cin >> h >> w;
	vector<string> vs;
	REP(i,h)
	{
		cin >> s;
		cout << s << endl << s << endl;
	}
}