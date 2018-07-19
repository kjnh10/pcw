#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()

const int MN = 710;

int n, m;
int col[MN], cmp[MN];
bool g[MN][MN];
int cnt;
vi vs[MN];

bool dfs(int v, int k, int c) {
	col[v] = c;
	cmp[v] = k;
	vs[k].pb(v);

	rep(i, n) if (i != v && !g[v][i]) {
		if (col[i] == -1) {
			if (!dfs(i, k, c ^ 1)) {
				return false;
			}
		} else if (col[i] == c) {
			return false;
		}
	}

	return true;
}

bool dp[MN][MN];

int main() {
	cin >> n >> m;

	rep(i, m) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		g[a][b] = g[b][a] = 1;
	}

	memset(col, -1, sizeof(col));

	int now = 0;

	rep(i, n) {
		if (col[i] == -1) {
			if (!dfs(i, now++, 0)) {
				puts("-1");
				return 0;
			}
		}
	}

	dp[0][0] = 1;

	rep(i, now) {
		int c[2] = {};
		for (int v : vs[i]) {
			++c[col[v]];
		}

		rep(j, MN) {
			if (dp[i][j]) {
				if (j + c[0] <= n) {
					dp[i+1][j + c[0]] = 1;
				}
				if (j + c[1] <= n) {
					dp[i+1][j + c[1]] = 1;
				}
			}
		}
	}

	int ret = 0;

	rep(i, MN) {
		if (dp[now][i]) {
			ret = max(ret, i * (n - i));
		}
	}

	cout << n * (n-1) / 2 - ret << endl;

	return 0;
}