#include <bits/stdc++.h>

using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n, d, x, y;
	cin >> n >> d >> x >> y;
	if (x % d != 0 || y % d != 0) {
		cout << 0 << endl;
		return 0;
	}
	x /= d;
	y /= d;
	x = abs(x);
	y = abs(y);

	double ans = 0.0;
	for (int i = x; i <= n; i++) {
		if (n - i < y) continue;
		if ((i - x) % 2 != 0 || (n - i - y) % 2 != 0) continue;
		double tmp = 1.0;
		int cnt = n;
		for (int j = 0; j < i; j++) {
			tmp *= n - j;
			tmp /= i - j;
			while (cnt > 0 && tmp > 1.0) {
				tmp /= 4;
				cnt--;
			}
		}
		for (int j = 0; j < (i - x) / 2; j++) {
			tmp *= i - j;
			tmp /= (i - x) / 2 - j;
			while (cnt > 0 && tmp > 1.0) {
				tmp /= 4;
				cnt--;
			}
		}
		for (int j = 0; j < (n - i - y) / 2; j++) {
			tmp *= n - i - j;
			tmp /= (n - i - y) / 2 - j;
			while (cnt > 0 && tmp > 1.0) {
				tmp /= 4;
				cnt--;
			}
		}
		for (int j = 0; j < cnt; j++) tmp /= 4;
		ans += tmp;
	}	
	cout << fixed << setprecision(10) << ans << endl;
	return 0;
}