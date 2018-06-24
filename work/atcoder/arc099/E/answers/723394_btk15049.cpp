#include<bits/stdc++.h>

using namespace std;
typedef long long LL;

#ifdef BTK
#define DEBUG if(1)
#else
#define CIN_ONLY if(1)
struct cww {cww() {CIN_ONLY{ios::sync_with_stdio(false); cin.tie(0);}}
}star;
#define DEBUG if(0)
#endif

#define ALL(v) (v).begin(),(v).end()
#define REC(ret, ...) std::function<ret (__VA_ARGS__)>
template <typename T>inline bool chmin(T &l, T r){bool a = l>r; if (a)l = r; return a;}
template <typename T>inline bool chmax(T &l, T r){bool a = l<r; if (a)l = r; return a;}
template <typename T>istream& operator>>(istream &is, vector<T> &v){for (auto &it : v)is >> it;return is;}

class range {private: struct I { int x; int operator*() { return x; }bool operator!=(I& lhs) { return x<lhs.x; }void operator++() { ++x; } }; I i, n;public:range(int n) :i({ 0 }), n({ n }) {}range(int i, int n) :i({ i }), n({ n }) {}I& begin() { return i; }I& end() { return n; }};

int d[1123][1123];
int col[1123];
int N, M;
int solve() {
	for (int i : range(N))for (int j : range(N))d[i][j] = 0;
	for (int i : range(N)) {
		col[i] = -1;
		d[i][i] = 1;
	}
	for (int i : range(M)) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		d[a][b] = d[b][a] = 1;
	}
	vector<pair<int, int>> c;
	stack<int> s;
	for (int i : range(N)) {
		if (col[i] != -1)continue;
		s.push(i);
		col[i] = 0;
		int cnt[2] = { 1,0 };
		while (s.size()) {
			int v = s.top(); s.pop();
			for (int u : range(N)) {
				if (d[v][u] == 0) {
					if (col[u] == -1) {
						col[u] = 1 - col[v];
						cnt[col[u]]++;
						s.push(u);
					}
					else {
						if (col[v] == col[u])return -1;
					}
				}
			}
		}
		c.push_back({ cnt[0],cnt[1] });
	}
	int ret = 1e9;
	vector<int> dp(N+1, 0);
	dp[0] = 1;
	for (auto &it:c) {
		vector<int> nxt(N + 1, 0);
		for (int i : range(N+1)) {
			if (dp[i] == 0)continue;
			nxt[i + it.first] = 1;
			nxt[i + it.second] = 1;
		}
		swap(dp, nxt);
	}
	for (int i : range(N + 1)) {
		if (dp[i]) {
			int a = i;
			int b = N - i;
			chmin(ret, a*(a - 1) / 2 + b * (b - 1) / 2);
		}
	}
	return ret;
}
int main() {
	while (cin >> N >> M)cout << solve() << endl;
	return 0;
}
