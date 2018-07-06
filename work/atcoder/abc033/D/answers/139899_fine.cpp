#include <bits/stdc++.h>

using namespace std;

const double PI = 3.14159265358979;
const double EPS = 1e-10;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<double> x(n), y(n);
	for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
	int ans[2] = {};
	for (int i = 0; i < n; i++) {
		vector<double> r;
		for (int j = 0; j < n; j++) {
			if (j == i) continue;
			double tmp = atan2(y[j] - y[i], x[j] - x[i]);
			r.push_back(tmp);
			r.push_back(tmp + 2 * PI);
		}

		sort(r.begin(), r.end());
		for (int j = 0; j < n - 1; j++) {
			int cnt1 = upper_bound(r.begin() + j, r.begin() + j + n - 1, r[j] + PI + EPS) - upper_bound(r.begin() + j, r.begin() + j + n - 1, r[j] + PI / 2 + EPS);
			int cnt2 = upper_bound(r.begin() + j, r.begin() + j + n - 1, r[j] + PI / 2 + EPS) - lower_bound(r.begin() + j, r.begin() + j + n - 1, r[j] + PI / 2 - EPS);
			ans[0] += cnt1;
			ans[1] += cnt2;
		}
	}
	long long sum = (long long)n * (n - 1) * (n - 2) / 6;
	cout << sum - ans[0] - ans[1]  << " " << ans[1] << " " << ans[0] << endl;
	return 0;
}