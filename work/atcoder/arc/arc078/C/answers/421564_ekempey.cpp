#include <iostream>
#include <algorithm>
#include <vector>

int main() {
	int n;
	std::cin >> n;

	std::vector<long long> a(n);
	long long R = 0;
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
		R += a[i];
	}

	long long L = 0;
	long long ans = 1e18;
	for (int i = 0; i < n - 1; i++) {
		L += a[i];
		R -= a[i];
		ans = std::min(ans, std::abs(L - R));
	}
	
	std::cout << ans << std::endl;
}
