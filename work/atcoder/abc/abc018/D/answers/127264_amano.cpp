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

int main()
{
	cin.sync_with_stdio(false); cout << fixed << setprecision(10);
	int n, m, p, q, r;
	cin >> n >> m >> p >> q >> r;
	vector<vi> mat(m, vi(n));
	REP(i, r)
	{
		int a, b, c; cin >> a >> b >> c;
		a--; b--;
		mat[b][a] = c;
	}
	int ans = 0;
	REP(i, (1 << n))
	{
		if (__builtin_popcount(i) != p) continue;
		vi v(m);
		REP(j, m)
		{
			int sum = 0;
			REP(k, n)
			{
				if ((i >> k) & 1) sum += mat[j][k];
			}
			v[j] = sum;
		}
		sort(v.rbegin(), v.rend());
		int tmp = 0;
		REP(j, q) tmp += v[j];
		chmax(ans, tmp);
	}
	cout << ans << endl;
	return 0;
}