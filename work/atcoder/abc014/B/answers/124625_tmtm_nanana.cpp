#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <array>
#include <vector>
#include <functional>
using namespace std;

int main(void) {
	int n, X, i, ans = 0;
	cin >> n >> X;
	vector<int> a(n);
	vector<int> bin(n);
	for (i = 0; i < n; i++) cin >> a[i];
	i = 0;
	while (i<n) {
		bin[i] = X % 2;
		X /= 2;
		i++;
	}
	for (i = 0; i < n; i++) {
		if (bin[i] == 1)ans += a[i];
	}
	cout << ans << endl;

	return 0;
}