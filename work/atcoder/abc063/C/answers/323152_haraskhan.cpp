#include <bits/stdc++.h>
using namespace std;
bool dp[100 * 1000];
int main() {
	int n;
	cin >> n;
	dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		for (int j = 100 * 100; j >= x; j--) {
			if (dp[j - x]) {
				dp[j] = true;
			}
		}
	}
	int ans = 0;
	for (int i = 100 * 100; i >= 0; i--) {
		if (i % 10 != 0 && dp[i]) {
			cout << i;
			return 0;
		}
	}
	cout << 0;
	return 0;
}
