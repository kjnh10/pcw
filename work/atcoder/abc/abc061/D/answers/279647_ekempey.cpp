#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

int main() {
	int n, m;
	std::cin >> n >> m;

	std::vector<int> us(m);
	std::vector<int> vs(m);
	std::vector<int> ws(m);
	for (int i = 0; i < m; i++) {
		std::cin >> us[i] >> vs[i] >> ws[i];
		us[i]--;
		vs[i]--;
	}

	constexpr long long INF = 1e18;
	std::vector<long long> d(n, -INF);

	d[0] = 0;
	for (int i = 0; i < 5000; i++) {
		for (int j = 0; j < m; j++) {
			d[vs[j]] = std::max(d[vs[j]], d[us[j]] + ws[j]);
		}
	}
	long long ans1 = d[n - 1];
	for (int i = 0; i < 5000; i++) {
		for (int j = 0; j < m; j++) {
			d[vs[j]] = std::max(d[vs[j]], d[us[j]] + ws[j]);
		}
	}
	long long ans2 = d[n - 1];
	if (ans1 != ans2) {
		std::cout << "inf" << std::endl;
	} else {
		std::cout << ans1 << std::endl;
	}
}