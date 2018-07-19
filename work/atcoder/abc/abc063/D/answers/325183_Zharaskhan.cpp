#include <bits/stdc++.h>
using namespace std;
long long a[100000 * 2];
long long n, A, B;
inline bool check(long long mid) {
	long long need = 0;
	for (int i = 1; i <= n; i++) {
		if ((a[i] + B - 1ll) / B <= mid) {
			continue;
		} else {
			//A * c + (mid - c) * B >= x
			//A * c + mid * B - Bc >= x
			//A * c - B * c >= x - mid * B
			//c * (A - B) >= x - mid * B
			//c >= x * mid * B / (A - B);
			long long x = a[i];
			long long c = (x - mid * B + (A - B) - 1ll) / (A - B);
			need += c;
			if (need > mid) {
				return false;
			}
		}
	}
	return need <= mid;
}
int main() {
	scanf("%lld%lld%lld", &n, &A, &B);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	sort(a + 1, a + 1 + n);
	reverse(a + 1, a + 1  +n);
	long long l = -1;
	long long r = 1e16;
	while (r - l > 1ll) {
		long long mid = (r + l )/ 2;
		if (check(mid)) {
			r = mid;
		} else {
			l = mid;
		}
	}
	cout << r;
	return 0;
}
