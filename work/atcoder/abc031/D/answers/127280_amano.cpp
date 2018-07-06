#include <bits/stdc++.h>
using namespace std;
#define FOR(i,k,n) for(int i = (int)(k); i < (int)(n); i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(a) a.begin(), a.end()
#define MS(m,v) memset(m,v,sizeof(m))
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> pii;
const int MOD = 1e9 + 7;
template<class T> T &chmin(T &a, const T &b) { return a = min(a, b); }
template<class T> T &chmax(T &a, const T &b) { return a = max(a, b); }
template<class T>
istream& operator >> (istream& is, vector<T>& v)
{
	for (auto &i : v) is >> i;
	return is;
}
template<class T>
ostream& operator<<(ostream& os, vector<T>& v)
{
	const string delimiter = "\n";
	REP(i, v.size())
	{
		os << v[i];
		if (i != v.size() - 1) os << delimiter;
	}
	return os;
}
/*--------------------template--------------------*/

int k, n;
vs v, w;
map<char, string> mp;

void solve(int r, int c, int p)
{
	if (r == n)
	{
		FOR(i, 1, k + 1)
		{
			cout << mp[i + '0'] << endl;
		}
		exit(EXIT_SUCCESS);
	}
	if (c == v[r].size())
	{
		if (p == w[r].size()) solve(r + 1, 0, 0);
		else return;
	}
	if (mp.count(v[r][c]))
	{
		string a = mp[v[r][c]];
		if (p + a.size() > w[r].size()) return;
		string b = w[r].substr(p, a.size());
		if (a != b) return;
		solve(r, c + 1, p + a.size());
	}
	else
	{
		FOR(i, 1, min(4, int(w[r].size() - p + 1)))
		{
			string a = w[r].substr(p, i);
			mp[v[r][c]] = a;
			solve(r, c + 1, p + a.size());
			mp.erase(v[r][c]);
		}
	}
	return;
}

int main()
{
	cin.sync_with_stdio(false); cout << fixed << setprecision(10);
	cin >> k >> n;
	v.resize(n); w.resize(n);
	REP(i, n) cin >> v[i] >> w[i];
	solve(0, 0, 0);
	return 0;
}