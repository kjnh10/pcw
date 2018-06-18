#include <iostream>
#include <functional>
#include <algorithm>
using namespace std;

int n, a[109], s;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n, greater<int>());
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) s += a[i];
		if (i % 2 == 1) s -= a[i];
	}
	cout << s << endl;
	return 0;
}