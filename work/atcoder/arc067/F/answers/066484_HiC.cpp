#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>

#define mp make_pair
#define pb push_back


typedef long long ll;
typedef long double ld;

using namespace std;

vector<pair<ll, int> > vv[210];
int n, m;
ll a[5100];
ll b[5100][210];
ll ad[5100];
ll dp[5100];

void add(int l, int r, ll d) {
	ad[l] += d;
	ad[r] -= d;
}
ll ans;

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i < n; ++i)
		scanf("%lld", a + i);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			scanf("%lld", &b[i][j]);
	for (int i = 0; i < n; ++i) {
		add(0, i, -a[i]);
		for (int j = 0; j < m; ++j) {
			int lst = i;
			while (!vv[j].empty() && vv[j].back().first < b[i][j]) {
				add(vv[j].back().second, lst, -vv[j].back().first);
				lst = vv[j].back().second;
				vv[j].pop_back();
			}
			add(lst, i + 1, b[i][j]);
			vv[j].push_back(make_pair(b[i][j], lst));
		}
		ll now = 0;
		for (int j = 0; j <= i + 1; ++j)
			now += ad[j], dp[j] += now, ad[j] = 0;
		for (int j = 0; j <= i; ++j) {
			ans = max(ans, dp[j]);
		}
	}
	cout << ans << "\n";
	return 0;
}


