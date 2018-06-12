#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

constexpr int MOD = 1e9 + 7;

struct modint {
	int n;
	modint(int n = 0) : n(n) {}
};

modint operator+(modint a, modint b) { return modint((a.n += b.n) >= MOD ? a.n - MOD : a.n); }
modint operator-(modint a, modint b) { return modint((a.n -= b.n) < 0 ? a.n + MOD : a.n); }
modint operator*(modint a, modint b) { return modint(1LL * a.n * b.n % MOD); }
modint &operator+=(modint &a, modint b) { return a = a + b; }
modint &operator-=(modint &a, modint b) { return a = a - b; }
modint &operator*=(modint &a, modint b) { return a = a * b; }

int main() {
	int n, m;
	std::cin >> n >> m;

	if (std::abs(n - m) >= 2) {
		std::cout << 0 << std::endl;
	} else if (std::abs(n - m) == 1) {
		modint ans = 1;

		for (int i = 1; i <= n; i++) {
			ans *= i;
		}
		for (int i = 1; i <= m; i++) {
			ans *= i;
		}

		std::cout << ans.n << std::endl;

	} else {
		modint ans = 1;

		for (int i = 1; i <= n; i++) {
			ans *= i;
		}
		for (int i = 1; i <= m; i++) {
			ans *= i;
		}
		ans *= 2;

		std::cout << ans.n << std::endl;

	}
}
