#include <bits/stdc++.h>
#define int long long
using namespace std;
const int INF = 1e9 + 7, MOD = 1e9 + 7;
const long long LINF = 1e18;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
signed main() {
	int n;
	string s;
	cin >> n >> s;
	int cnt = 0, ans = -1;
	for (int i = 0; i < n; i++) {
		string cmp1 = s.substr(0, i), cmp2 = s.substr(i, n - i);
		cnt = 0;
		for (int j = 0; j < 26; j++) {
			char Cmp = 'a' + j;
			if (cmp1.find(Cmp) != string::npos && cmp2.find(Cmp) != string::npos) {
				cnt++;
			}
		}
		ans = max(ans, cnt);
	}
	cout << ans << endl;
	return 0;
}