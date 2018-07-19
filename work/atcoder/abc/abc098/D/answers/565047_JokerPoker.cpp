#include <bits/stdc++.h>

using namespace std;

int c[300300];

int main() {
	int n;
	scanf("%d", &n);
	vector<int> a;
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		a.push_back(x);
	}
	int l = 0, r = 0;
	int now = 0;
	long long ans = 0;
	while (l < n) {
		while (r < n && (now ^ a[r]) == now + a[r]) {
			now ^= a[r++], ans++;
		}
		now ^= a[l++];
		ans += r - l;
	}
	printf("%lld\n", ans);
	return 0;
}