#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<long long> a(n);
	
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	long long ans = LLONG_MAX;
	for (long long i = -100; i <= 100; i++) {
		long long cost = 0;
		for (int j = 0; j < n; j++) {
			cost += (i - a[j]) * (i - a[j]);
		}
		ans = min(ans, cost);
	}
	cout << ans << endl;
}