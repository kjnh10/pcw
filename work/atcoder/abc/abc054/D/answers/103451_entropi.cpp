#include <bits/stdc++.h>
using namespace std;

#define FORE(i, a) for (auto i = a.begin(); i != a.end(); ++i)
#define REPU(i, a, b) for (int i = (a); i < (b); ++i)
#define REPD(i, a, b) for (int i = (a); i > (b); --i)
#define MEM(a, x) memset(a, x, sizeof(a))
#define ALL(a) a.begin(), a.end()
#define UNIQUE(a) a.erase(unique(ALL(a)), a.end())

vector<string> split(const string &s, char c) {
	vector<string> v; stringstream ss(s); string x;
	while (getline(ss, x, c)) v.push_back(x);
	return v;
}
#define DEBUG(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
void err(vector<string>::iterator it) {}
template<typename T, typename... Args>
void err(vector<string>::iterator it, T a, Args... args) {
	cerr << "[DEBUG] " << it -> substr((*it)[0] == ' ', it -> length()) << " = " << a << '\n';
	err(++it, args...);
}

typedef long long ll;
const int MOD = 1000000007;

template<class T, class U> inline T tmin(T a, U b) { return (a < b) ? a : b; }
template<class T, class U> inline T tmax(T a, U b) { return (a > b) ? a : b; }
template<class T, class U> inline void amax(T &a, U b) { if (b > a) a = b; }
template<class T, class U> inline void amin(T &a, U b) { if (b < a) a = b; }
template<class T> T gcd(T a, T b) { while (b != 0) { T c = a; a = b; b = c % b; } return a; }

const int N = 405;
int dp[N][N], tmp[N][N], a[N], b[N], c[N];

int main(int argc, char *argv[]) {
	ios_base::sync_with_stdio(false);

	MEM(dp, -1);

	dp[0][0] = 0;
	int n, ma, mb; cin >> n >> ma >> mb;
	REPU(i, 0, n) {
		cin >> a[i] >> b[i] >> c[i];
	}
	REPU(it, 0, n) {
		REPU(i, 0, N) REPU(j, 0, N) tmp[i][j] = dp[i][j];
		for (int i = 0; i + a[it] < N; ++i) {
			for (int j = 0; j + b[it] < N; ++j) if (dp[i][j] >= 0) {
				int& x = tmp[i + a[it]][j + b[it]];
				if (x == -1) x = dp[i][j] + c[it];
				else amin(x, dp[i][j] + c[it]);
			}
		}
		REPU(i, 0, N) REPU(j, 0, N) dp[i][j] = tmp[i][j];
	}
	int ans = INT_MAX;
	REPU(i, 1, N) REPU(j, 1, N) if (dp[i][j] >= 0) {
		int g = gcd(i, j);
		int ni = i / g, nj = j / g;
		if (ni == ma && nj == mb) amin(ans, dp[i][j]);
	}
	if (ans == INT_MAX) ans = -1;
	cout << ans << endl;

	return 0;
}
