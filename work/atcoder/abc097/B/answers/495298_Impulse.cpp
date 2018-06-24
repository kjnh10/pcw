#include <bits/stdc++.h>
#define int long long
using namespace std;
const int INF = 1e9 + 7, MOD = 1e9 + 7;
const long long LINF = 1e18;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
signed main() {
	int x, ans = 1;
	cin >> x;
	for (int i = 1; i < x; i++) {
		for (int j = 2; j < x; j++) {
			if ((long long)pow(i, j) <= x) {
				ans = max(ans, (long long)pow(i, j));
			}
		}
	}
	cout << ans << endl;
	return 0;
}