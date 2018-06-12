#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <queue>

using namespace std;

const int mod = 1e9 + 7;

struct modint {
	int n;
	modint(int n = 0) : n(n) {}
};

modint operator+(modint a, modint b) { return modint((a.n += b.n) >= mod ? a.n - mod : a.n); }
modint operator-(modint a, modint b) { return modint((a.n -= b.n) < 0 ? a.n + mod : a.n); }
modint operator*(modint a, modint b) { return modint(1LL * a.n * b.n % mod); }
modint &operator+=(modint &a, modint b) { return a = a + b; }
modint &operator-=(modint &a, modint b) { return a = a - b; }
modint &operator*=(modint &a, modint b) { return a = a * b; }

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> x(n);
	vector<int> y(m);
	for (int i = 0; i < n; i++) {
		cin >> x[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> y[i];
	}
	modint unit;
	for (int i = 0; i + 1 < n; i++) {
		unit += modint(i + 1) * modint(n - i - 1) * (x[i + 1] - x[i]);
	}
	modint ans;
	for (int i = 0; i + 1 < m; i++) {
		ans += modint(i + 1) * modint(m - i - 1) * unit * (y[i + 1] - y[i]);
	}
	cout << ans.n << endl;
}
