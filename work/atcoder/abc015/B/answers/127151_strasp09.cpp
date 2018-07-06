#include <bits/stdc++.h>
const long long MOD = 1000000007;
const int INF = INT_MAX / 2;
const long double PI = 3.1415926;
#define FOR(i, r, n) for(int i=(ll)(r); i<(ll)(n); i++) 
#define REP(i, n) FOR(i, (0), n)
#define ALL(r) r.begin(), r.end()
#define ll long long int
using namespace std;
string s;
vector<ll> v;
vector<pair<ll, ll>> vp;
vector<vector<ll>> vv(110, vector<ll>(50, 0));
vector<tuple<ll, ll, ll>> vt;
set<ll> st;
map<ll, ll> mp;

int main()
{
	int n;
	cin >> n;
	vector<int> vi;
	int sum=0;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		if (a != 0) {
			vi.push_back(a);
			sum += a;
		}
	}
	if (sum%vi.size() == 0) cout << sum / vi.size() << endl;
	else cout << sum / vi.size() + 1 << endl;
}